#include "mypwm.h"
#include "driver/mcpwm.h"

#define SERVO_PULSE_GPIO1 (4)  // GPIO connects to the PWM signal line
#define SERVO_PULSE_GPIO2 (2)  // GPIO connects to the PWM signal line
#define SERVO_PULSE_GPIO3 (14) // GPIO connects to the PWM signal line
#define SERVO_PULSE_GPIO4 (15) // GPIO connects to the PWM signal line
#define SERVO_PULSE_GPIO5 (13) // GPIO connects to the PWM signal line
#define SERVO_PULSE_GPIO6 (12) // GPIO connects to the PWM signal line

void initPwm(void)
{
    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0A, SERVO_PULSE_GPIO1);
    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0B, SERVO_PULSE_GPIO2);
    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM1A, SERVO_PULSE_GPIO3);
    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM1B, SERVO_PULSE_GPIO4);
    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM2A, SERVO_PULSE_GPIO5);
    mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM2B, SERVO_PULSE_GPIO6);
    mcpwm_config_t pwm_config = {
        .frequency = 50,
        .cmpr_a = 0,
        .counter_mode = MCPWM_UP_COUNTER,
        .duty_mode = MCPWM_DUTY_MODE_0,
    };
    mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_0, &pwm_config);
    mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_1, &pwm_config);
    mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_2, &pwm_config);
    mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, 1500);
    mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_B, 1600);
    mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_1, MCPWM_OPR_A, 1800);
    mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_1, MCPWM_OPR_B, 1900);
    mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_2, MCPWM_OPR_A, 1200);
    mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_2, MCPWM_OPR_B, 1300);
}

void setPwm(int channel, int duty)
{
    switch (channel)
    {
    case 1:
        mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, duty);
        break;
    case 2:
        mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_B, duty);
        break;
    case 3:
        mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_1, MCPWM_OPR_A, duty);
        break;
    case 4:
        mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_1, MCPWM_OPR_B, duty);
        break;
    case 5:
        mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_2, MCPWM_OPR_A, duty);
        break;
    case 6:
        mcpwm_set_duty_in_us(MCPWM_UNIT_0, MCPWM_TIMER_2, MCPWM_OPR_B, duty);
        break;
    default:
        break;
    }
}