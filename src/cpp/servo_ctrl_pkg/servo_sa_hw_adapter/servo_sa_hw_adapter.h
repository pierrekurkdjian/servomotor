#ifndef _servo_sa_hw_adapter_h_
#define _servo_sa_hw_adapter_h_

#include "ocs_core_fwk.h"
#include "ocs_io_fwk.h"
#include "../../include/servo_dcs_port_types.h"

class servoSaHwAdapterSetup;

namespace gmt
{

class servoSaHwAdapter : public EthercatAdapter
{
    public:
        servoSaHwAdapter(
            const std::string& comp_uri,
            const std::string& comp_name,
            const std::string& comp_host,
            int comp_port,
            const std::string& comp_acl,
            float comp_scan_rate);

        virtual ~servoSaHwAdapter();

        void setup() override;
        void step(bool setup_ok) override;

    protected:

        typedef servoSaHwAdapterSetup Setup;

        virtual void create_config() override;

        // Create state variables

        // // Input port declaration
        // std::array<bool, 2>      enable;              // Actuator Enable Input
        // std::array<bool, 2>      close_loop_hw_ad;    // close loop
        // std::array<float_t, 2>   pwm_offset_hw_ad;    // pwm offset
        // sa_force                 force_sp_hw_ad;      // SP forces
        // std::array<uint16_t, 2>  msthb_hw_ad;         // Master heartbeat
        //
        // // Output port declaration
        // std::array<bool, 2>      enable_check;        // Actuator Enable Output Check
        // std::array<bool, 2>      close_loop_status;   // close loop status
        // sa_error                 err_hw_ad;           // SA errors
        // sa_force                 force_rb;            // Readback forces
        // sa_force                 force_sp_status;     // SP Forces value
        // sa_pwm  pwm_status;          // Cylinders PWM value    //sa_pwm  //Pierre4
        // std::array<uint16_t, 2>  slvhb_hw_ad;         // Slave Heartbeat
        //
        // std::array<float_t, 2>      pwm_offset_out;  //Pierre4

        // Define alarms for port and state_var health conditions

        // Configuration properties

        // uint16_t motor_state_goal;
        // uint16_t motor_velocity_goal;
        // uint16_t motor_state_value;
        // uint16_t motor_velocity_value;
        // uint16_t motor_position_value;

        uint16_t motor_state_goal;
        uint16_t motor_velocity_goal;
        uint16_t motor_state_value;
        uint16_t motor_velocity_value;
        uint16_t motor_position_value;

        // std::string date_string;
        // uint64_t date_write;
        // uint64_t date_read;

};

} // namespace gmt

#endif   // _servo_sa_hw_adapter_h_
