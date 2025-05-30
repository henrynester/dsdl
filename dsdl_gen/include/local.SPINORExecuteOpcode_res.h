#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>


#define LOCAL_SPINOREXECUTEOPCODE_RESPONSE_MAX_SIZE 1
#define LOCAL_SPINOREXECUTEOPCODE_RESPONSE_SIGNATURE (0x52D1E06453399CA1ULL)
#define LOCAL_SPINOREXECUTEOPCODE_RESPONSE_ID 210

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
class local_SPINORExecuteOpcode_cxx_iface;
#endif

struct local_SPINORExecuteOpcodeResponse {
#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
    using cxx_iface = local_SPINORExecuteOpcode_cxx_iface;
#endif
    bool can_do;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t local_SPINORExecuteOpcodeResponse_encode(struct local_SPINORExecuteOpcodeResponse* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool local_SPINORExecuteOpcodeResponse_decode(const CanardRxTransfer* transfer, struct local_SPINORExecuteOpcodeResponse* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _local_SPINORExecuteOpcodeResponse_encode(uint8_t* buffer, uint32_t* bit_ofs, struct local_SPINORExecuteOpcodeResponse* msg, bool tao);
static inline bool _local_SPINORExecuteOpcodeResponse_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct local_SPINORExecuteOpcodeResponse* msg, bool tao);
void _local_SPINORExecuteOpcodeResponse_encode(uint8_t* buffer, uint32_t* bit_ofs, struct local_SPINORExecuteOpcodeResponse* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    canardEncodeScalar(buffer, *bit_ofs, 1, &msg->can_do);
    *bit_ofs += 1;
}

/*
 decode local_SPINORExecuteOpcodeResponse, return true on failure, false on success
*/
bool _local_SPINORExecuteOpcodeResponse_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct local_SPINORExecuteOpcodeResponse* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;
    canardDecodeScalar(transfer, *bit_ofs, 1, false, &msg->can_do);
    *bit_ofs += 1;

    return false; /* success */
}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct local_SPINORExecuteOpcodeResponse sample_local_SPINORExecuteOpcodeResponse_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
#endif
#endif
