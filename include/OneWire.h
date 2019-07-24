#pragma once
#include "HydraTypes.h"
#include "freertos/FreeRTOS.h"
#include "driver/rmt.h"
#include "owb.h"


namespace Hydra {
    class OneWire {
    public:
        void * operator new(size_t size);
        void operator delete(void *p);
        
        OneWire(uint8_t gpio_num, rmt_channel_t tx_channel, rmt_channel_t rx_channel);
        ~OneWire();
        const OneWireBus_ROMCode& ReadRomCode();
        owb_status Reset(bool &devPresent);
        owb_status WriteRomCode();
        owb_status ReadByte(uint8_t &data);
        
        owb_status WriteByte(uint8_t data);
        owb_status ReadBytes(uint8_t * buffer, size_t len);
        owb_status WriteBytes(const uint8_t * buffer, size_t len);
    private:
        OneWireBus *Bus;
        owb_rmt_driver_info Info;
        OneWireBus_ROMCode RomCode;
    };
}
    