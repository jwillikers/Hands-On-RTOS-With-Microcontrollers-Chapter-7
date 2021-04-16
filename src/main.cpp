#include <FreeRTOS.h>
#include <Nucleo_F767ZI_GPIO.hpp>
#include <Nucleo_F767ZI_Init.hpp>
#include <iostream>
#include <stm32f7xx_hal.h>
#include <task.h>

/**
 * 	function prototypes
 */
void GreenTask(void *argument);
[[noreturn]] void BlueTask(void *argument);
[[noreturn]] void RedTask(void *argument);
void lookBusy();

// the address of Task2Handle is passed to xTaskCreate.
// this global variable will be used by Task3 to delete BlueTask.
TaskHandle_t blueTaskHandle;

// some common variables to use for each task
// 128 * 4 = 512 bytes
//(recommended min stack size per task)
static constexpr uint8_t stack_size{128};

// define stack and task control block (TCB) for the red task
static StackType_t RedTaskStack[stack_size];
static StaticTask_t RedTaskTCB;

void GreenTask(void *) {
  GreenLed.On();
  vTaskDelay(1500 / portTICK_PERIOD_MS);
  GreenLed.Off();

  vTaskDelete(nullptr);

  GreenLed.On();
}

[[noreturn]] void BlueTask(void *) {
  while (true) {
    BlueLed.On();
    vTaskDelay(200 / portTICK_PERIOD_MS);
    BlueLed.Off();
    vTaskDelay(200 / portTICK_PERIOD_MS);
  }
}

[[noreturn]] void RedTask(void *) {
  bool first_run{true};
  while (true) {
    lookBusy();

    RedLed.On();
    vTaskDelay(500 / portTICK_PERIOD_MS);
    RedLed.Off();
    vTaskDelay(500 / portTICK_PERIOD_MS);

    if (first_run) {
      vTaskDelete(blueTaskHandle);
      first_run = false;
    }
  }
}

void lookBusy() {
  [[maybe_unused]] volatile uint32_t dontCare{};
  for (int i{}; i < 125'000; i++) {
    dontCare = i % 4;
  }
}

///* configSUPPORT_STATIC_ALLOCATION is set to 1, so the application must
///provide an
// implementation of vApplicationGetIdleTaskMemory() to provide the memory that
// is used by the Idle task. */ void vApplicationGetIdleTaskMemory(StaticTask_t
// **ppxIdleTaskTCBBuffer,
//                                   StackType_t **ppxIdleTaskStackBuffer,
//                                   uint32_t *pulIdleTaskStackSize)
//{
//    /* If the buffers to be provided to the Idle task are declared inside this
// function then they must be declared static - otherwise they will be allocated
// on the stack and so not exists after this function exits. */
//    static StaticTask_t xIdleTaskTCB;
//    static StackType_t uxIdleTaskStack[configMINIMAL_STACK_SIZE];
//
//    /* Pass out a pointer to the StaticTask_t structure in which the Idle
//    task's state will be stored. */ *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;
//
//    /* Pass out the array that will be used as the Idle task's stack. */
//    *ppxIdleTaskStackBuffer = uxIdleTaskStack;
//
//    /* Pass out the size of the array pointed to by *ppxIdleTaskStackBuffer.
//    Note that, as the array is necessarily of type StackType_t,
//    configMINIMAL_STACK_SIZE is specified in words, not bytes. */
//    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
//}
///*-----------------------------------------------------------*/
//
///* configSUPPORT_STATIC_ALLOCATION and configUSE_TIMERS are both set to 1, so
///the
// application must provide an implementation of
// vApplicationGetTimerTaskMemory() to provide the memory that is used by the
// Timer service task. */ void vApplicationGetTimerTaskMemory(StaticTask_t
// **ppxTimerTaskTCBBuffer,
//                                    StackType_t **ppxTimerTaskStackBuffer,
//                                    uint32_t *pulTimerTaskStackSize)
//{
//    /* If the buffers to be provided to the Timer task are declared inside
//    this
// function then they must be declared static - otherwise they will be allocated
// on the stack and so not exists after this function exits. */
//    static StaticTask_t xTimerTaskTCB;
//    static StackType_t uxTimerTaskStack[configTIMER_TASK_STACK_DEPTH];
//
//    /* Pass out a pointer to the StaticTask_t structure in which the Timer
//    task's state will be stored. */
//    *ppxTimerTaskTCBBuffer = &xTimerTaskTCB;
//
//    /* Pass out the array that will be used as the Timer task's stack. */
//    *ppxTimerTaskStackBuffer = uxTimerTaskStack;
//
//    /* Pass out the size of the array pointed to by *ppxTimerTaskStackBuffer.
//    Note that, as the array is necessarily of type StackType_t,
//    configTIMER_TASK_STACK_DEPTH is specified in words, not bytes. */
//    *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
//}

//void vApplicationTickHook() {}

int main() {
  HWInit();

  assert_param(xTaskCreate(GreenTask, "GreenTask", stack_size, nullptr,
                           tskIDLE_PRIORITY + 2, nullptr) == pdPASS);
  assert_param(xTaskCreate(BlueTask, "BlueTask", stack_size, nullptr,
                           tskIDLE_PRIORITY + 1, &blueTaskHandle) == pdPASS);
  xTaskCreateStatic(RedTask, "RedTask", stack_size, nullptr,
                    tskIDLE_PRIORITY + 1, RedTaskStack, &RedTaskTCB);

  vTaskStartScheduler();

  assert_param(false);

  return 0;
}
