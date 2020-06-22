//
// Created by viciu on 08.06.2020.
//

#ifndef NAMF_MAIN_H
#define NAMF_MAIN_H

#include "variables.h"
#include "system/scheduler.h"
#include "helpers.h"
#include "html-content.h"
#include <sps30.h>

#define SPS_MAX_SERIAL_LEN 32

namespace SPS30 {
    extern bool started;

    extern int16_t ret;
    extern uint8_t auto_clean_days;
    extern uint32_t auto_clean;
    extern struct sps30_measurement sum ;
    extern unsigned int measurement_count;
    extern char serial[SPS_MAX_SERIAL_LEN];

    extern void zeroMeasurmentStruct(sps30_measurement &str);

    extern void addMeasurementStruct(sps30_measurement &storage, sps30_measurement reading);

    extern unsigned long init();

    extern unsigned long process(SimpleScheduler::LoopEventType e);

    //we will reset average even on API failure
    extern void afterSend(bool success);

    //return JSON with results
    extern void results(String &s);

    extern void resultsAsHTML(String &page_content);

}

#endif //NAMF_MAIN_H
