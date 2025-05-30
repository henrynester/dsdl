#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>
#include <local.SPINORCommand.h>


#define LOCAL_SPINORARRAYCOMMAND_MAX_SIZE 76
#define LOCAL_SPINORARRAYCOMMAND_SIGNATURE (0xC4B8E59E9F7B73E9ULL)
#define LOCAL_SPINORARRAYCOMMAND_ID 20100

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
class local_SPINORArrayCommand_cxx_iface;
#endif

struct local_SPINORArrayCommand {
#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
    using cxx_iface = local_SPINORArrayCommand_cxx_iface;
#endif
    struct { uint8_t len; struct local_SPINORCommand data[15]; }commands;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t local_SPINORArrayCommand_encode(struct local_SPINORArrayCommand* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool local_SPINORArrayCommand_decode(const CanardRxTransfer* transfer, struct local_SPINORArrayCommand* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _local_SPINORArrayCommand_encode(uint8_t* buffer, uint32_t* bit_ofs, struct local_SPINORArrayCommand* msg, bool tao);
static inline bool _local_SPINORArrayCommand_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct local_SPINORArrayCommand* msg, bool tao);
void _local_SPINORArrayCommand_encode(uint8_t* buffer, uint32_t* bit_ofs, struct local_SPINORArrayCommand* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
    const uint8_t commands_len = msg->commands.len > 15 ? 15 : msg->commands.len;
#pragma GCC diagnostic pop
    if (!tao) {
        canardEncodeScalar(buffer, *bit_ofs, 4, &commands_len);
        *bit_ofs += 4;
    }
    for (size_t i=0; i < commands_len; i++) {
        _local_SPINORCommand_encode(buffer, bit_ofs, &msg->commands.data[i], false);
    }
}

/*
 decode local_SPINORArrayCommand, return true on failure, false on success
*/
bool _local_SPINORArrayCommand_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct local_SPINORArrayCommand* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;
    if (!tao) {
        canardDecodeScalar(transfer, *bit_ofs, 4, false, &msg->commands.len);
        *bit_ofs += 4;
    }


    if (tao) {
        msg->commands.len = 0;
        size_t max_len = 15;
        uint32_t max_bits = (transfer->payload_len*8)-7; // TAO elements must be >= 8 bits
        while (max_bits > *bit_ofs) {
            if (!max_len-- || _local_SPINORCommand_decode(transfer, bit_ofs, &msg->commands.data[msg->commands.len], false)) {return true;}
            msg->commands.len++;
        }
    } else {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
        if (msg->commands.len > 15) {
            return true; /* invalid value */
        }
#pragma GCC diagnostic pop
        for (size_t i=0; i < msg->commands.len; i++) {
            if (_local_SPINORCommand_decode(transfer, bit_ofs, &msg->commands.data[i], false)) {return true;}
        }
    }

    return false; /* success */
}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct local_SPINORArrayCommand sample_local_SPINORArrayCommand_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
BROADCAST_MESSAGE_CXX_IFACE(local_SPINORArrayCommand, LOCAL_SPINORARRAYCOMMAND_ID, LOCAL_SPINORARRAYCOMMAND_SIGNATURE, LOCAL_SPINORARRAYCOMMAND_MAX_SIZE);
#endif
#endif
