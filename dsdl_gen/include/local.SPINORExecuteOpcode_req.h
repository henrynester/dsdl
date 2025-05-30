#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>


#define LOCAL_SPINOREXECUTEOPCODE_REQUEST_MAX_SIZE 1
#define LOCAL_SPINOREXECUTEOPCODE_REQUEST_SIGNATURE (0x52D1E06453399CA1ULL)
#define LOCAL_SPINOREXECUTEOPCODE_REQUEST_ID 210

#define LOCAL_SPINOREXECUTEOPCODE_REQUEST_OPCODE_START_HOMING 1
#define LOCAL_SPINOREXECUTEOPCODE_REQUEST_OPCODE_START_ENCODER_CALIBRATION 2

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
class local_SPINORExecuteOpcode_cxx_iface;
#endif

struct local_SPINORExecuteOpcodeRequest {
#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
    using cxx_iface = local_SPINORExecuteOpcode_cxx_iface;
#endif
    uint8_t opcode;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t local_SPINORExecuteOpcodeRequest_encode(struct local_SPINORExecuteOpcodeRequest* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool local_SPINORExecuteOpcodeRequest_decode(const CanardRxTransfer* transfer, struct local_SPINORExecuteOpcodeRequest* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _local_SPINORExecuteOpcodeRequest_encode(uint8_t* buffer, uint32_t* bit_ofs, struct local_SPINORExecuteOpcodeRequest* msg, bool tao);
static inline bool _local_SPINORExecuteOpcodeRequest_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct local_SPINORExecuteOpcodeRequest* msg, bool tao);
void _local_SPINORExecuteOpcodeRequest_encode(uint8_t* buffer, uint32_t* bit_ofs, struct local_SPINORExecuteOpcodeRequest* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    canardEncodeScalar(buffer, *bit_ofs, 8, &msg->opcode);
    *bit_ofs += 8;
}

/*
 decode local_SPINORExecuteOpcodeRequest, return true on failure, false on success
*/
bool _local_SPINORExecuteOpcodeRequest_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct local_SPINORExecuteOpcodeRequest* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;
    canardDecodeScalar(transfer, *bit_ofs, 8, false, &msg->opcode);
    *bit_ofs += 8;

    return false; /* success */
}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct local_SPINORExecuteOpcodeRequest sample_local_SPINORExecuteOpcodeRequest_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
#endif
#endif
