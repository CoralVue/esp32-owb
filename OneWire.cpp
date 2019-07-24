#include "HydraTypes.h"
#include "OneWire.h"
#include "owb.h"
#include "owb_rmt.h"


namespace Hydra {
    OneWire::OneWire(uint8_t gpioNum, rmt_channel_t txChannel, rmt_channel_t rxChannel) {
        Bus =  owb_rmt_initialize(&Info, gpioNum, txChannel, rxChannel);
    }
    
    OneWire::~OneWire() {
        owb_uninitialize(Bus);
        Bus = nullptr;
    }
    const OneWireBus_ROMCode& OneWire::ReadRomCode() {
        owb_read_rom(Bus, &RomCode);
        return RomCode;
    }

    owb_status OneWire::Reset(bool &devPresent) {
        return owb_reset(Bus, &devPresent);
    }
    owb_status OneWire::WriteRomCode() {
        return owb_write_rom_code(Bus, RomCode);
    }
    owb_status OneWire::ReadByte(uint8_t &data) {
        return owb_read_byte(Bus, &data);
    }
        
    owb_status OneWire::WriteByte(uint8_t data) {
        return owb_write_byte(Bus, data);
    }

    owb_status OneWire::ReadBytes(uint8_t * buffer, size_t len) {
        return owb_read_bytes(Bus, buffer, len);
    }
    owb_status OneWire::WriteBytes(const uint8_t * buffer, size_t len) {
        return owb_write_bytes(Bus, buffer, len);
    }
   
    void * OneWire::operator new(size_t size) {
        return heap_caps_malloc(size, MALLOC_CAP_INTERNAL |  MALLOC_CAP_8BIT | MALLOC_CAP_DMA); 
    }
    void OneWire::operator delete(void *p) {
        free(p);
    }
}
