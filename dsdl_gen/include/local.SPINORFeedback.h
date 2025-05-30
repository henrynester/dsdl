#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <canard.h>


#define LOCAL_SPINORFEEDBACK_MAX_SIZE 12
#define LOCAL_SPINORFEEDBACK_SIGNATURE (0x54A44BBDE8688BD9ULL)
#define LOCAL_SPINORFEEDBACK_ID 20105

#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
class local_SPINORFeedback_cxx_iface;
#endif

struct local_SPINORFeedback {
#if defined(__cplusplus) && defined(DRONECAN_CXX_WRAPPERS)
    using cxx_iface = local_SPINORFeedback_cxx_iface;
#endif
    float position;
    float velocity;
    float torque;
};

#ifdef __cplusplus
extern "C"
{
#endif

uint32_t local_SPINORFeedback_encode(struct local_SPINORFeedback* msg, uint8_t* buffer
#if CANARD_ENABLE_TAO_OPTION
    , bool tao
#endif
);
bool local_SPINORFeedback_decode(const CanardRxTransfer* transfer, struct local_SPINORFeedback* msg);

#if defined(CANARD_DSDLC_INTERNAL)
static inline void _local_SPINORFeedback_encode(uint8_t* buffer, uint32_t* bit_ofs, struct local_SPINORFeedback* msg, bool tao);
static inline bool _local_SPINORFeedback_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct local_SPINORFeedback* msg, bool tao);
void _local_SPINORFeedback_encode(uint8_t* buffer, uint32_t* bit_ofs, struct local_SPINORFeedback* msg, bool tao) {
    (void)buffer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;

    canardEncodeScalar(buffer, *bit_ofs, 32, &msg->position);
    *bit_ofs += 32;
    canardEncodeScalar(buffer, *bit_ofs, 32, &msg->velocity);
    *bit_ofs += 32;
    canardEncodeScalar(buffer, *bit_ofs, 32, &msg->torque);
    *bit_ofs += 32;
}

/*
 decode local_SPINORFeedback, return true on failure, false on success
*/
bool _local_SPINORFeedback_decode(const CanardRxTransfer* transfer, uint32_t* bit_ofs, struct local_SPINORFeedback* msg, bool tao) {
    (void)transfer;
    (void)bit_ofs;
    (void)msg;
    (void)tao;
    canardDecodeScalar(transfer, *bit_ofs, 32, true, &msg->position);
    *bit_ofs += 32;

    canardDecodeScalar(transfer, *bit_ofs, 32, true, &msg->velocity);
    *bit_ofs += 32;

    canardDecodeScalar(transfer, *bit_ofs, 32, true, &msg->torque);
    *bit_ofs += 32;

    return false; /* success */
}
#endif
#ifdef CANARD_DSDLC_TEST_BUILD
struct local_SPINORFeedback sample_local_SPINORFeedback_msg(void);
#endif
#ifdef __cplusplus
} // extern "C"

#ifdef DRONECAN_CXX_WRAPPERS
#include <canard/cxx_wrappers.h>
BROADCAST_MESSAGE_CXX_IFACE(local_SPINORFeedback, LOCAL_SPINORFEEDBACK_ID, LOCAL_SPINORFEEDBACK_SIGNATURE, LOCAL_SPINORFEEDBACK_MAX_SIZE);
#endif
#endif
