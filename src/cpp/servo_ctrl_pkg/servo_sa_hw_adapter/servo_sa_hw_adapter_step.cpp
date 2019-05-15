#include "servo_sa_hw_adapter.h"

using namespace gmt;

void servoSaHwAdapter::step(bool setup_ok) {
    if(setup_ok) {                     // this will be executed only if port setup has been received
        //pwm_offset_out[0] = pwm_offset_hw_ad[0];  //Pierre4
        if (is_step_rate(100)) {      // this will be executed every 1000 steps

          if ((motor_state_value >> 3) & 0x01) { // status: fault
              motor_state_goal = 0x80;
              log_info("Status: fault");
          } else if ((motor_state_value >> 6) & 0x01) { // status: disabled
              motor_state_goal = 0x06;
              log_info("Status: switch on disabled");
          } else if (((motor_state_value >> 0) & 0x01) &&
                     !((motor_state_value >> 1) & 0x01)) { // status: ready and no switched on
              motor_state_goal = 0x07;
              log_info("Status: ready to switch on");
          } else if ((motor_state_value >> 1) & 0x01) { // status: switched on
              if (motor_state_goal != 0xf) {
                  log_info("Status: Switched on");
                  motor_velocity_goal = 2000;
              }
              motor_state_goal = 0xf;
          }

          log_info("mmmotor_state_goal " + std::to_string(motor_state_goal) + " " + std::to_string(motor_state_goal%16));
          log_info("motor_velocity_goal " + std::to_string(motor_velocity_goal));
          log_info("motor_state_value " + std::to_string(motor_state_value) + " " + std::to_string(motor_state_value%16));
          log_info("motor_velocity_value " + std::to_string(motor_velocity_value));
          log_info("motor_position_value " + std::to_string(motor_position_value));
          //log_info("date_read  " + date_read);

          // date_string = random_string(8);
          // log_info("date_string " + date_string);
          // date_write = StringToU64(date_string);
          // log_info("date_write " + date_write);


          // log_info("motor_state_value " + std::to_string(motor_state_value) + " " + std::to_string(motor_state_value%16));
          // log_info("motor_velocity_value " + std::to_string(motor_velocity_value));
          // log_info("motor_position_value " + std::to_string(motor_position_value));

            // log_info("sdo_read_update_req     "         + std::to_string(sdo_read_update_req));   //Pierre2
            // log_info("sdo_read_update_done    "         + std::to_string(sdo_read_update_done));  //Pierre2
            // //log_info("SA1 Pwm offset at hw_ad "         + std::to_string(pwm_offset_hw_ad[0]));
            // log_info("pwm_offset_hw_ad        "         + std::to_string(pwm_offset_hw_ad[0]));
            // log_info("pwm_offset_out          "         + std::to_string(pwm_offset_out[0]));
            // log_info("SA1 Close_loop_status at hw_ad "  + std::to_string(close_loop_status[0]));
            // log_info("\n");
        /*    log_info("step  = "                         + std::to_string(step_counter));
            log_info("SA1 enable at hw_ad = "           + std::to_string(enable_check[0]));
            log_info("SA1 Force read back X = "         + std::to_string(force_rb.X[0]));
            log_info("SA1 Force read back Y = "         + std::to_string(force_rb.Y[0]));
            log_info("SA1 Force read back Z = "         + std::to_string(force_rb.Z[0]));
            log_info("SA1 Error at hw ad = "            + std::to_string(err_hw_ad.err_io[0]));
            log_info("SA1 Close_loop at hw_ad "         + std::to_string(close_loop_hw_ad[0]));
            log_info("SA1 Close_loop_status at hw_ad "  + std::to_string(close_loop_status[0]));
            log_info("SA1 Pwm offset at hw_ad "         + std::to_string(pwm_offset_hw_ad[0]));
            log_info("SA1 force_sp_x at hw_ad "         + std::to_string(force_sp_hw_ad.X[0]));
            log_info("SA1 force_sp_y at hw_ad "         + std::to_string(force_sp_hw_ad.Y[0]));
            log_info("SA1 force_sp_z at hw_ad "         + std::to_string(force_sp_hw_ad.Z[0]));
            log_info("SA1 force_sp_x_status at hw_ad "  + std::to_string(force_sp_status.X[0]));
            log_info("SA1 force_sp_y_status at hw_ad "  + std::to_string(force_sp_status.Y[0]));
            log_info("SA1 force_sp_x_status at hw_ad "  + std::to_string(force_sp_status.Z[0]));
            log_info("SA1 PWM Cylinder 1 at hw_ad "     + std::to_string(pwm_status.pwservo[0]));
            log_info("SA1 PWM Cylinder 2 at hw_ad "     + std::to_string(pwm_status.pwm2[0]));
            log_info("SA1 PWM Cylinder 3 at hw_ad "     + std::to_string(pwm_status.pwm3[0]));
            log_info("SA1 Slave heartbeat at hw_ad "    + std::to_string(slvhb_hw_ad[0]));


            log_info("SA2 enable at hw_ad = "           + std::to_string(enable_check[1]));
            log_info("SA2 Force read back X = "         + std::to_string(force_rb.X[1]));
            log_info("SA2 Force read back Y = "         + std::to_string(force_rb.Y[1]));
            log_info("SA2 Force read back Z = "         + std::to_string(force_rb.Z[1]));
            log_info("SA2 Error at hw ad = "            + std::to_string(err_hw_ad.err_io[1]));
            log_info("SA2 Close_loop at hw_ad "         + std::to_string(close_loop_hw_ad[1]));
            log_info("SA2 Close_loop_status at hw_ad "  + std::to_string(close_loop_status[1]));
            log_info("SA2 Pwm offset at hw_ad "         + std::to_string(pwm_offset_hw_ad[1]));
            log_info("SA2 force_sp_x at hw_ad "         + std::to_string(force_sp_hw_ad.X[1]));
            log_info("SA2 force_sp_y at hw_ad "         + std::to_string(force_sp_hw_ad.Y[1]));
            log_info("SA2 force_sp_z at hw_ad "         + std::to_string(force_sp_hw_ad.Z[1]));
            log_info("SA2 force_sp_x_status at hw_ad "  + std::to_string(force_sp_status.X[1]));
            log_info("SA2 force_sp_y_status at hw_ad "  + std::to_string(force_sp_status.Y[1]));
            log_info("SA2 force_sp_x_status at hw_ad "  + std::to_string(force_sp_status.Z[1]));
            log_info("SA2 PWM Cylinder 1 at hw_ad "     + std::to_string(pwm_status.pwservo[1]));
            log_info("SA2 PWM Cylinder 2 at hw_ad "     + std::to_string(pwm_status.pwm2[1]));
            log_info("SA2 PWM Cylinder 3 at hw_ad "     + std::to_string(pwm_status.pwm3[1]));
            log_info("SA2 Slave heartbeat at hw_ad "    + std::to_string(slvhb_hw_ad[1]));*/
        }
    }
}
