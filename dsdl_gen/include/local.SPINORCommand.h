#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>


#define LOCAL_SPINORCOMMAND_MAX_SIZE 5
#define LOCAL_SPINORCOMMAND_SIGNATURE (0x22293733C26E0BDEULL)

#define LOCAL_SPINORCOMMAND_COMMAND_TYPE_POSITION 1
#define LOCAL_SPINORCOMMAND_COMMAND_TYPE_VELOCITY 2
#define LOCAL_SPINORCOMMAND_COMMAND_TYPE_TORQUE 3


struct local_SPINORCommand {
    uint8_t command_type;
    float command;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t local_SPINORCommand_encode(struct local_SPINORCommand* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool local_SPINORCommand_decode(const CanardRxTransfer* transfer, struct local_SPINORCommand* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _local_SPINORCommand_encode(uint8_t* buffer, uint32_t* bit_ofs, struct local_SPINORCommand* msg, bool tao);
static inline bool _local_SPINORCommand_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct local_SPINORCommand* msg, bool tao);
void _local_SPINORCommand_encode(uint8_t* buffer, uint32_t* bit_ofs, struct local_SPINORCommand* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->command_type);
    *bit_ofs += 8;
    canardEncodeScalar(buffer, *bit_ofs, 32, &msg->command);
    *bit_ofs += 32;
}

/*
 decode local_SPINORCommand, return true on failure, false on success
*/
bool _local_SPINORCommand_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct local_SPINORCommand* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;
    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->command_type);
    *bit_ofs += 8;

    canardDecodeScalar(transfer, *bit_ofs, 32, true, &msg->command);
    *bit_ofs += 32;

    return false; /* success */
}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct local_SPINORCommand sample_local_SPINORCommand_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
#endif
#endif
