/**
 * @file can_app.h
 *
 * @defgroup CANAPP    Application Module for canbus
 *
 * @brief The application layer module for canbus
 *
 */

#ifndef CAN_APP_H
#define CAN_APP_H

#include "conf.h"
#include "dbg_vrb.h"
#include "../lib/bit_utils.h"
#include "can.h"
#include "can_ids.h"
#include "machine.h"
#include "usart.h"

void can_app_print_msg(can_t *msg);
void can_app_task(void);
void can_app_send_state(void);

void can_app_msg_extractors_switch(can_t *msg);

void can_app_extractor_mic17_state(can_t *msg);
void can_app_extractor_mic17_msc(can_t *msg);

void can_app_extractor_msc19_1_state(can_t *msg);
void can_app_extractor_msc19_1_voltage(can_t *msg);
void can_app_extractor_msc19_2_state(can_t *msg);
void can_app_extractor_msc19_2_voltage(can_t *msg);
void can_app_extractor_msc19_3_state(can_t *msg);
void can_app_extractor_msc19_3_voltage(can_t *msg);
void can_app_extractor_msc19_4_state(can_t *msg);
void can_app_extractor_msc19_4_data(can_t *msg);
void can_app_extractor_msc19_5_state(can_t *msg);
void can_app_extractor_msc19_5_data(can_t *msg);

void check_can(void);

#ifdef CAN_ON
#define CAN_APP_SEND_STATE_CLK_DIV  CAN_APP_SEND_STATE_FREQ
#define CAN_APP_SEND_ADC_CLK_DIV    CAN_APP_SEND_ADC_FREQ
#else
#define CAN_APP_SEND_STATE_CLK_DIV  1
#define CAN_APP_SEND_ADC_CLK_DIV    1
#endif

#define CAN_APP_CHECKS_WITHOUT_MSC19_MSG  100
#define CAN_APP_CHECKS_WITHOUT_MIC17_MSG  200

// can_app_checks
uint8_t can_app_checks_without_mic17_msg;
uint8_t can_app_checks_without_msc19_1_msg;
uint8_t can_app_checks_without_msc19_2_msg;
uint8_t can_app_checks_without_msc19_3_msg;
uint8_t can_app_checks_without_msc19_4_msg;
uint8_t can_app_checks_without_msc19_5_msg;

#endif /* ifndef CAN_APP_H */
