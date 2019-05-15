#include "servo_sa_hw_adapter.h"

using namespace gmt;

servoSaHwAdapter::servoSaHwAdapter(
        const std::string& comp_uri,
        const std::string& comp_name,
        const std::string& comp_host,
        int comp_port,
        const std::string& comp_acl,
        float comp_scan_rate)
    : EthercatAdapter(comp_uri, comp_name, comp_host, comp_port, comp_acl, comp_scan_rate)
{
    motor_state_goal = 0;
    motor_velocity_goal = 10000;
    log_info("creating controller");
}

servoSaHwAdapter::~servoSaHwAdapter() {
}
