#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/uart.h"

#define TAG "LD2410B"
#define UART_NUM        UART_NUM_2
#define TX_PIN          17
#define RX_PIN          18
#define BAUD_RATE       256000

void app_main(void)
{
    uart_config_t uart_cfg = {
        .baud_rate = BAUD_RATE,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_DEFAULT,
    };

    uart_driver_install(UART_NUM, 2048, 0, 0, NULL, 0);
    uart_param_config(UART_NUM, &uart_cfg);
    uart_set_pin(UART_NUM, TX_PIN, RX_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);

    ESP_LOGI(TAG, "======================");
    ESP_LOGI(TAG, "  LD2410B 监听中");
    ESP_LOGI(TAG, "  TX <-> RX 必须交叉接");
    ESP_LOGI(TAG, "======================");

    uint8_t buf[128];
    while(1) {
        int len = uart_read_bytes(UART_NUM, buf, 128, pdMS_TO_TICKS(300));
        if(len > 0) {
            ESP_LOGI(TAG, "✅ 有人！！！！！");
        } else {
            ESP_LOGW(TAG, "❌ 无人");
        }
    }
}