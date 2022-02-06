#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_StabilizerService_stParam_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_StabilizerService_stParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Float64MultiArray.h"
#include "hrpsys_ros_bridge/OpenHRP_StabilizerService_SupportPolygonVertices.h"
#include "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_Footstep.h"
#include "hrpsys_ros_bridge/OpenHRP_StabilizerService_IKLimbParameters.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_StabilizerService_stParam : public ros::Msg
  {
    public:
      float k_tpcc_p[2];
      float k_tpcc_x[2];
      float k_brot_p[2];
      float k_brot_tc[2];
      float eefm_k1[2];
      float eefm_k2[2];
      float eefm_k3[2];
      float eefm_zmp_delay_time_const[2];
      float eefm_ref_zmp_aux[2];
      typedef std_msgs::Float64MultiArray _eefm_rot_damping_gain_type;
      _eefm_rot_damping_gain_type eefm_rot_damping_gain;
      typedef std_msgs::Float64MultiArray _eefm_rot_time_const_type;
      _eefm_rot_time_const_type eefm_rot_time_const;
      typedef std_msgs::Float64MultiArray _eefm_pos_damping_gain_type;
      _eefm_pos_damping_gain_type eefm_pos_damping_gain;
      typedef std_msgs::Float64MultiArray _eefm_pos_time_const_support_type;
      _eefm_pos_time_const_support_type eefm_pos_time_const_support;
      typedef std_msgs::Float64MultiArray _eefm_swing_rot_spring_gain_type;
      _eefm_swing_rot_spring_gain_type eefm_swing_rot_spring_gain;
      typedef std_msgs::Float64MultiArray _eefm_swing_rot_time_const_type;
      _eefm_swing_rot_time_const_type eefm_swing_rot_time_const;
      typedef std_msgs::Float64MultiArray _eefm_swing_pos_spring_gain_type;
      _eefm_swing_pos_spring_gain_type eefm_swing_pos_spring_gain;
      typedef std_msgs::Float64MultiArray _eefm_swing_pos_time_const_type;
      _eefm_swing_pos_time_const_type eefm_swing_pos_time_const;
      typedef std_msgs::Float64MultiArray _eefm_ee_moment_limit_type;
      _eefm_ee_moment_limit_type eefm_ee_moment_limit;
      uint32_t eefm_pos_compensation_limit_length;
      typedef float _eefm_pos_compensation_limit_type;
      _eefm_pos_compensation_limit_type st_eefm_pos_compensation_limit;
      _eefm_pos_compensation_limit_type * eefm_pos_compensation_limit;
      uint32_t eefm_rot_compensation_limit_length;
      typedef float _eefm_rot_compensation_limit_type;
      _eefm_rot_compensation_limit_type st_eefm_rot_compensation_limit;
      _eefm_rot_compensation_limit_type * eefm_rot_compensation_limit;
      typedef float _eefm_pos_time_const_swing_type;
      _eefm_pos_time_const_swing_type eefm_pos_time_const_swing;
      typedef float _eefm_pos_transition_time_type;
      _eefm_pos_transition_time_type eefm_pos_transition_time;
      typedef float _eefm_pos_margin_time_type;
      _eefm_pos_margin_time_type eefm_pos_margin_time;
      typedef float _eefm_leg_inside_margin_type;
      _eefm_leg_inside_margin_type eefm_leg_inside_margin;
      typedef float _eefm_leg_outside_margin_type;
      _eefm_leg_outside_margin_type eefm_leg_outside_margin;
      typedef float _eefm_leg_front_margin_type;
      _eefm_leg_front_margin_type eefm_leg_front_margin;
      typedef float _eefm_leg_rear_margin_type;
      _eefm_leg_rear_margin_type eefm_leg_rear_margin;
      float eefm_body_attitude_control_gain[2];
      float eefm_body_attitude_control_time_const[2];
      typedef float _eefm_cogvel_cutoff_freq_type;
      _eefm_cogvel_cutoff_freq_type eefm_cogvel_cutoff_freq;
      typedef float _eefm_wrench_alpha_blending_type;
      _eefm_wrench_alpha_blending_type eefm_wrench_alpha_blending;
      typedef float _eefm_alpha_cutoff_freq_type;
      _eefm_alpha_cutoff_freq_type eefm_alpha_cutoff_freq;
      typedef float _eefm_gravitational_acceleration_type;
      _eefm_gravitational_acceleration_type eefm_gravitational_acceleration;
      typedef float _eefm_ee_pos_error_p_gain_type;
      _eefm_ee_pos_error_p_gain_type eefm_ee_pos_error_p_gain;
      typedef float _eefm_ee_rot_error_p_gain_type;
      _eefm_ee_rot_error_p_gain_type eefm_ee_rot_error_p_gain;
      typedef float _eefm_ee_error_cutoff_freq_type;
      _eefm_ee_error_cutoff_freq_type eefm_ee_error_cutoff_freq;
      uint32_t eefm_support_polygon_vertices_sequence_length;
      typedef hrpsys_ros_bridge::OpenHRP_StabilizerService_SupportPolygonVertices _eefm_support_polygon_vertices_sequence_type;
      _eefm_support_polygon_vertices_sequence_type st_eefm_support_polygon_vertices_sequence;
      _eefm_support_polygon_vertices_sequence_type * eefm_support_polygon_vertices_sequence;
      typedef bool _eefm_use_force_difference_control_type;
      _eefm_use_force_difference_control_type eefm_use_force_difference_control;
      typedef bool _eefm_use_swing_damping_type;
      _eefm_use_swing_damping_type eefm_use_swing_damping;
      float eefm_swing_damping_force_thre[3];
      float eefm_swing_damping_moment_thre[3];
      float eefm_swing_rot_damping_gain[3];
      float eefm_swing_pos_damping_gain[3];
      typedef std_msgs::Float64MultiArray _eefm_ee_forcemoment_distribution_weight_type;
      _eefm_ee_forcemoment_distribution_weight_type eefm_ee_forcemoment_distribution_weight;
      typedef int64_t _st_algorithm_type;
      _st_algorithm_type st_algorithm;
      typedef int64_t _controller_mode_type;
      _controller_mode_type controller_mode;
      typedef float _transition_time_type;
      _transition_time_type transition_time;
      uint32_t is_ik_enable_length;
      typedef bool _is_ik_enable_type;
      _is_ik_enable_type st_is_ik_enable;
      _is_ik_enable_type * is_ik_enable;
      uint32_t is_feedback_control_enable_length;
      typedef bool _is_feedback_control_enable_type;
      _is_feedback_control_enable_type st_is_feedback_control_enable;
      _is_feedback_control_enable_type * is_feedback_control_enable;
      uint32_t is_zmp_calc_enable_length;
      typedef bool _is_zmp_calc_enable_type;
      _is_zmp_calc_enable_type st_is_zmp_calc_enable;
      _is_zmp_calc_enable_type * is_zmp_calc_enable;
      typedef float _cop_check_margin_type;
      _cop_check_margin_type cop_check_margin;
      float cp_check_margin[4];
      float tilt_margin[2];
      float ref_capture_point[2];
      float act_capture_point[2];
      float cp_offset[2];
      typedef float _contact_decision_threshold_type;
      _contact_decision_threshold_type contact_decision_threshold;
      typedef std_msgs::Float64MultiArray _foot_origin_offset_type;
      _foot_origin_offset_type foot_origin_offset;
      typedef int64_t _emergency_check_mode_type;
      _emergency_check_mode_type emergency_check_mode;
      uint32_t end_effector_list_length;
      typedef hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep _end_effector_list_type;
      _end_effector_list_type st_end_effector_list;
      _end_effector_list_type * end_effector_list;
      typedef bool _is_estop_while_walking_type;
      _is_estop_while_walking_type is_estop_while_walking;
      uint32_t ik_limb_parameters_length;
      typedef hrpsys_ros_bridge::OpenHRP_StabilizerService_IKLimbParameters _ik_limb_parameters_type;
      _ik_limb_parameters_type st_ik_limb_parameters;
      _ik_limb_parameters_type * ik_limb_parameters;
      typedef bool _use_limb_stretch_avoidance_type;
      _use_limb_stretch_avoidance_type use_limb_stretch_avoidance;
      typedef float _limb_stretch_avoidance_time_const_type;
      _limb_stretch_avoidance_time_const_type limb_stretch_avoidance_time_const;
      float limb_stretch_avoidance_vlimit[2];
      uint32_t limb_length_margin_length;
      typedef float _limb_length_margin_type;
      _limb_length_margin_type st_limb_length_margin;
      _limb_length_margin_type * limb_length_margin;
      typedef float _detection_time_to_air_type;
      _detection_time_to_air_type detection_time_to_air;
      float root_rot_compensation_limit[2];
      typedef bool _use_zmp_truncation_type;
      _use_zmp_truncation_type use_zmp_truncation;

    OpenHRP_StabilizerService_stParam():
      k_tpcc_p(),
      k_tpcc_x(),
      k_brot_p(),
      k_brot_tc(),
      eefm_k1(),
      eefm_k2(),
      eefm_k3(),
      eefm_zmp_delay_time_const(),
      eefm_ref_zmp_aux(),
      eefm_rot_damping_gain(),
      eefm_rot_time_const(),
      eefm_pos_damping_gain(),
      eefm_pos_time_const_support(),
      eefm_swing_rot_spring_gain(),
      eefm_swing_rot_time_const(),
      eefm_swing_pos_spring_gain(),
      eefm_swing_pos_time_const(),
      eefm_ee_moment_limit(),
      eefm_pos_compensation_limit_length(0), eefm_pos_compensation_limit(NULL),
      eefm_rot_compensation_limit_length(0), eefm_rot_compensation_limit(NULL),
      eefm_pos_time_const_swing(0),
      eefm_pos_transition_time(0),
      eefm_pos_margin_time(0),
      eefm_leg_inside_margin(0),
      eefm_leg_outside_margin(0),
      eefm_leg_front_margin(0),
      eefm_leg_rear_margin(0),
      eefm_body_attitude_control_gain(),
      eefm_body_attitude_control_time_const(),
      eefm_cogvel_cutoff_freq(0),
      eefm_wrench_alpha_blending(0),
      eefm_alpha_cutoff_freq(0),
      eefm_gravitational_acceleration(0),
      eefm_ee_pos_error_p_gain(0),
      eefm_ee_rot_error_p_gain(0),
      eefm_ee_error_cutoff_freq(0),
      eefm_support_polygon_vertices_sequence_length(0), eefm_support_polygon_vertices_sequence(NULL),
      eefm_use_force_difference_control(0),
      eefm_use_swing_damping(0),
      eefm_swing_damping_force_thre(),
      eefm_swing_damping_moment_thre(),
      eefm_swing_rot_damping_gain(),
      eefm_swing_pos_damping_gain(),
      eefm_ee_forcemoment_distribution_weight(),
      st_algorithm(0),
      controller_mode(0),
      transition_time(0),
      is_ik_enable_length(0), is_ik_enable(NULL),
      is_feedback_control_enable_length(0), is_feedback_control_enable(NULL),
      is_zmp_calc_enable_length(0), is_zmp_calc_enable(NULL),
      cop_check_margin(0),
      cp_check_margin(),
      tilt_margin(),
      ref_capture_point(),
      act_capture_point(),
      cp_offset(),
      contact_decision_threshold(0),
      foot_origin_offset(),
      emergency_check_mode(0),
      end_effector_list_length(0), end_effector_list(NULL),
      is_estop_while_walking(0),
      ik_limb_parameters_length(0), ik_limb_parameters(NULL),
      use_limb_stretch_avoidance(0),
      limb_stretch_avoidance_time_const(0),
      limb_stretch_avoidance_vlimit(),
      limb_length_margin_length(0), limb_length_margin(NULL),
      detection_time_to_air(0),
      root_rot_compensation_limit(),
      use_zmp_truncation(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 2; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->k_tpcc_p[i]);
      }
      for( uint32_t i = 0; i < 2; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->k_tpcc_x[i]);
      }
      for( uint32_t i = 0; i < 2; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->k_brot_p[i]);
      }
      for( uint32_t i = 0; i < 2; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->k_brot_tc[i]);
      }
      for( uint32_t i = 0; i < 2; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->eefm_k1[i]);
      }
      for( uint32_t i = 0; i < 2; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->eefm_k2[i]);
      }
      for( uint32_t i = 0; i < 2; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->eefm_k3[i]);
      }
      for( uint32_t i = 0; i < 2; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->eefm_zmp_delay_time_const[i]);
      }
      for( uint32_t i = 0; i < 2; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->eefm_ref_zmp_aux[i]);
      }
      offset += this->eefm_rot_damping_gain.serialize(outbuffer + offset);
      offset += this->eefm_rot_time_const.serialize(outbuffer + offset);
      offset += this->eefm_pos_damping_gain.serialize(outbuffer + offset);
      offset += this->eefm_pos_time_const_support.serialize(outbuffer + offset);
      offset += this->eefm_swing_rot_spring_gain.serialize(outbuffer + offset);
      offset += this->eefm_swing_rot_time_const.serialize(outbuffer + offset);
      offset += this->eefm_swing_pos_spring_gain.serialize(outbuffer + offset);
      offset += this->eefm_swing_pos_time_const.serialize(outbuffer + offset);
      offset += this->eefm_ee_moment_limit.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->eefm_pos_compensation_limit_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->eefm_pos_compensation_limit_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->eefm_pos_compensation_limit_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->eefm_pos_compensation_limit_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->eefm_pos_compensation_limit_length);
      for( uint32_t i = 0; i < eefm_pos_compensation_limit_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->eefm_pos_compensation_limit[i]);
      }
      *(outbuffer + offset + 0) = (this->eefm_rot_compensation_limit_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->eefm_rot_compensation_limit_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->eefm_rot_compensation_limit_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->eefm_rot_compensation_limit_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->eefm_rot_compensation_limit_length);
      for( uint32_t i = 0; i < eefm_rot_compensation_limit_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->eefm_rot_compensation_limit[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->eefm_pos_time_const_swing);
      offset += serializeAvrFloat64(outbuffer + offset, this->eefm_pos_transition_time);
      offset += serializeAvrFloat64(outbuffer + offset, this->eefm_pos_margin_time);
      offset += serializeAvrFloat64(outbuffer + offset, this->eefm_leg_inside_margin);
      offset += serializeAvrFloat64(outbuffer + offset, this->eefm_leg_outside_margin);
      offset += serializeAvrFloat64(outbuffer + offset, this->eefm_leg_front_margin);
      offset += serializeAvrFloat64(outbuffer + offset, this->eefm_leg_rear_margin);
      for( uint32_t i = 0; i < 2; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->eefm_body_attitude_control_gain[i]);
      }
      for( uint32_t i = 0; i < 2; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->eefm_body_attitude_control_time_const[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->eefm_cogvel_cutoff_freq);
      offset += serializeAvrFloat64(outbuffer + offset, this->eefm_wrench_alpha_blending);
      offset += serializeAvrFloat64(outbuffer + offset, this->eefm_alpha_cutoff_freq);
      offset += serializeAvrFloat64(outbuffer + offset, this->eefm_gravitational_acceleration);
      offset += serializeAvrFloat64(outbuffer + offset, this->eefm_ee_pos_error_p_gain);
      offset += serializeAvrFloat64(outbuffer + offset, this->eefm_ee_rot_error_p_gain);
      offset += serializeAvrFloat64(outbuffer + offset, this->eefm_ee_error_cutoff_freq);
      *(outbuffer + offset + 0) = (this->eefm_support_polygon_vertices_sequence_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->eefm_support_polygon_vertices_sequence_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->eefm_support_polygon_vertices_sequence_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->eefm_support_polygon_vertices_sequence_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->eefm_support_polygon_vertices_sequence_length);
      for( uint32_t i = 0; i < eefm_support_polygon_vertices_sequence_length; i++){
      offset += this->eefm_support_polygon_vertices_sequence[i].serialize(outbuffer + offset);
      }
      union {
        bool real;
        uint8_t base;
      } u_eefm_use_force_difference_control;
      u_eefm_use_force_difference_control.real = this->eefm_use_force_difference_control;
      *(outbuffer + offset + 0) = (u_eefm_use_force_difference_control.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->eefm_use_force_difference_control);
      union {
        bool real;
        uint8_t base;
      } u_eefm_use_swing_damping;
      u_eefm_use_swing_damping.real = this->eefm_use_swing_damping;
      *(outbuffer + offset + 0) = (u_eefm_use_swing_damping.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->eefm_use_swing_damping);
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->eefm_swing_damping_force_thre[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->eefm_swing_damping_moment_thre[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->eefm_swing_rot_damping_gain[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->eefm_swing_pos_damping_gain[i]);
      }
      offset += this->eefm_ee_forcemoment_distribution_weight.serialize(outbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_st_algorithm;
      u_st_algorithm.real = this->st_algorithm;
      *(outbuffer + offset + 0) = (u_st_algorithm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_st_algorithm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_st_algorithm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_st_algorithm.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_st_algorithm.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_st_algorithm.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_st_algorithm.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_st_algorithm.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->st_algorithm);
      union {
        int64_t real;
        uint64_t base;
      } u_controller_mode;
      u_controller_mode.real = this->controller_mode;
      *(outbuffer + offset + 0) = (u_controller_mode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_controller_mode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_controller_mode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_controller_mode.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_controller_mode.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_controller_mode.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_controller_mode.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_controller_mode.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->controller_mode);
      offset += serializeAvrFloat64(outbuffer + offset, this->transition_time);
      *(outbuffer + offset + 0) = (this->is_ik_enable_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->is_ik_enable_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->is_ik_enable_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->is_ik_enable_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->is_ik_enable_length);
      for( uint32_t i = 0; i < is_ik_enable_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_is_ik_enablei;
      u_is_ik_enablei.real = this->is_ik_enable[i];
      *(outbuffer + offset + 0) = (u_is_ik_enablei.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_ik_enable[i]);
      }
      *(outbuffer + offset + 0) = (this->is_feedback_control_enable_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->is_feedback_control_enable_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->is_feedback_control_enable_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->is_feedback_control_enable_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->is_feedback_control_enable_length);
      for( uint32_t i = 0; i < is_feedback_control_enable_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_is_feedback_control_enablei;
      u_is_feedback_control_enablei.real = this->is_feedback_control_enable[i];
      *(outbuffer + offset + 0) = (u_is_feedback_control_enablei.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_feedback_control_enable[i]);
      }
      *(outbuffer + offset + 0) = (this->is_zmp_calc_enable_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->is_zmp_calc_enable_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->is_zmp_calc_enable_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->is_zmp_calc_enable_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->is_zmp_calc_enable_length);
      for( uint32_t i = 0; i < is_zmp_calc_enable_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_is_zmp_calc_enablei;
      u_is_zmp_calc_enablei.real = this->is_zmp_calc_enable[i];
      *(outbuffer + offset + 0) = (u_is_zmp_calc_enablei.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_zmp_calc_enable[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->cop_check_margin);
      for( uint32_t i = 0; i < 4; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->cp_check_margin[i]);
      }
      for( uint32_t i = 0; i < 2; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->tilt_margin[i]);
      }
      for( uint32_t i = 0; i < 2; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->ref_capture_point[i]);
      }
      for( uint32_t i = 0; i < 2; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->act_capture_point[i]);
      }
      for( uint32_t i = 0; i < 2; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->cp_offset[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->contact_decision_threshold);
      offset += this->foot_origin_offset.serialize(outbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_emergency_check_mode;
      u_emergency_check_mode.real = this->emergency_check_mode;
      *(outbuffer + offset + 0) = (u_emergency_check_mode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_emergency_check_mode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_emergency_check_mode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_emergency_check_mode.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_emergency_check_mode.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_emergency_check_mode.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_emergency_check_mode.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_emergency_check_mode.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->emergency_check_mode);
      *(outbuffer + offset + 0) = (this->end_effector_list_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->end_effector_list_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->end_effector_list_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->end_effector_list_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->end_effector_list_length);
      for( uint32_t i = 0; i < end_effector_list_length; i++){
      offset += this->end_effector_list[i].serialize(outbuffer + offset);
      }
      union {
        bool real;
        uint8_t base;
      } u_is_estop_while_walking;
      u_is_estop_while_walking.real = this->is_estop_while_walking;
      *(outbuffer + offset + 0) = (u_is_estop_while_walking.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_estop_while_walking);
      *(outbuffer + offset + 0) = (this->ik_limb_parameters_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ik_limb_parameters_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ik_limb_parameters_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ik_limb_parameters_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ik_limb_parameters_length);
      for( uint32_t i = 0; i < ik_limb_parameters_length; i++){
      offset += this->ik_limb_parameters[i].serialize(outbuffer + offset);
      }
      union {
        bool real;
        uint8_t base;
      } u_use_limb_stretch_avoidance;
      u_use_limb_stretch_avoidance.real = this->use_limb_stretch_avoidance;
      *(outbuffer + offset + 0) = (u_use_limb_stretch_avoidance.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->use_limb_stretch_avoidance);
      offset += serializeAvrFloat64(outbuffer + offset, this->limb_stretch_avoidance_time_const);
      for( uint32_t i = 0; i < 2; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->limb_stretch_avoidance_vlimit[i]);
      }
      *(outbuffer + offset + 0) = (this->limb_length_margin_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->limb_length_margin_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->limb_length_margin_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->limb_length_margin_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->limb_length_margin_length);
      for( uint32_t i = 0; i < limb_length_margin_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->limb_length_margin[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->detection_time_to_air);
      for( uint32_t i = 0; i < 2; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->root_rot_compensation_limit[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_use_zmp_truncation;
      u_use_zmp_truncation.real = this->use_zmp_truncation;
      *(outbuffer + offset + 0) = (u_use_zmp_truncation.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->use_zmp_truncation);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint32_t i = 0; i < 2; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->k_tpcc_p[i]));
      }
      for( uint32_t i = 0; i < 2; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->k_tpcc_x[i]));
      }
      for( uint32_t i = 0; i < 2; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->k_brot_p[i]));
      }
      for( uint32_t i = 0; i < 2; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->k_brot_tc[i]));
      }
      for( uint32_t i = 0; i < 2; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eefm_k1[i]));
      }
      for( uint32_t i = 0; i < 2; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eefm_k2[i]));
      }
      for( uint32_t i = 0; i < 2; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eefm_k3[i]));
      }
      for( uint32_t i = 0; i < 2; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eefm_zmp_delay_time_const[i]));
      }
      for( uint32_t i = 0; i < 2; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eefm_ref_zmp_aux[i]));
      }
      offset += this->eefm_rot_damping_gain.deserialize(inbuffer + offset);
      offset += this->eefm_rot_time_const.deserialize(inbuffer + offset);
      offset += this->eefm_pos_damping_gain.deserialize(inbuffer + offset);
      offset += this->eefm_pos_time_const_support.deserialize(inbuffer + offset);
      offset += this->eefm_swing_rot_spring_gain.deserialize(inbuffer + offset);
      offset += this->eefm_swing_rot_time_const.deserialize(inbuffer + offset);
      offset += this->eefm_swing_pos_spring_gain.deserialize(inbuffer + offset);
      offset += this->eefm_swing_pos_time_const.deserialize(inbuffer + offset);
      offset += this->eefm_ee_moment_limit.deserialize(inbuffer + offset);
      uint32_t eefm_pos_compensation_limit_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      eefm_pos_compensation_limit_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      eefm_pos_compensation_limit_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      eefm_pos_compensation_limit_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->eefm_pos_compensation_limit_length);
      if(eefm_pos_compensation_limit_lengthT > eefm_pos_compensation_limit_length)
        this->eefm_pos_compensation_limit = (float*)realloc(this->eefm_pos_compensation_limit, eefm_pos_compensation_limit_lengthT * sizeof(float));
      eefm_pos_compensation_limit_length = eefm_pos_compensation_limit_lengthT;
      for( uint32_t i = 0; i < eefm_pos_compensation_limit_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_eefm_pos_compensation_limit));
        memcpy( &(this->eefm_pos_compensation_limit[i]), &(this->st_eefm_pos_compensation_limit), sizeof(float));
      }
      uint32_t eefm_rot_compensation_limit_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      eefm_rot_compensation_limit_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      eefm_rot_compensation_limit_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      eefm_rot_compensation_limit_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->eefm_rot_compensation_limit_length);
      if(eefm_rot_compensation_limit_lengthT > eefm_rot_compensation_limit_length)
        this->eefm_rot_compensation_limit = (float*)realloc(this->eefm_rot_compensation_limit, eefm_rot_compensation_limit_lengthT * sizeof(float));
      eefm_rot_compensation_limit_length = eefm_rot_compensation_limit_lengthT;
      for( uint32_t i = 0; i < eefm_rot_compensation_limit_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_eefm_rot_compensation_limit));
        memcpy( &(this->eefm_rot_compensation_limit[i]), &(this->st_eefm_rot_compensation_limit), sizeof(float));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eefm_pos_time_const_swing));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eefm_pos_transition_time));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eefm_pos_margin_time));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eefm_leg_inside_margin));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eefm_leg_outside_margin));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eefm_leg_front_margin));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eefm_leg_rear_margin));
      for( uint32_t i = 0; i < 2; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eefm_body_attitude_control_gain[i]));
      }
      for( uint32_t i = 0; i < 2; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eefm_body_attitude_control_time_const[i]));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eefm_cogvel_cutoff_freq));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eefm_wrench_alpha_blending));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eefm_alpha_cutoff_freq));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eefm_gravitational_acceleration));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eefm_ee_pos_error_p_gain));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eefm_ee_rot_error_p_gain));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eefm_ee_error_cutoff_freq));
      uint32_t eefm_support_polygon_vertices_sequence_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      eefm_support_polygon_vertices_sequence_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      eefm_support_polygon_vertices_sequence_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      eefm_support_polygon_vertices_sequence_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->eefm_support_polygon_vertices_sequence_length);
      if(eefm_support_polygon_vertices_sequence_lengthT > eefm_support_polygon_vertices_sequence_length)
        this->eefm_support_polygon_vertices_sequence = (hrpsys_ros_bridge::OpenHRP_StabilizerService_SupportPolygonVertices*)realloc(this->eefm_support_polygon_vertices_sequence, eefm_support_polygon_vertices_sequence_lengthT * sizeof(hrpsys_ros_bridge::OpenHRP_StabilizerService_SupportPolygonVertices));
      eefm_support_polygon_vertices_sequence_length = eefm_support_polygon_vertices_sequence_lengthT;
      for( uint32_t i = 0; i < eefm_support_polygon_vertices_sequence_length; i++){
      offset += this->st_eefm_support_polygon_vertices_sequence.deserialize(inbuffer + offset);
        memcpy( &(this->eefm_support_polygon_vertices_sequence[i]), &(this->st_eefm_support_polygon_vertices_sequence), sizeof(hrpsys_ros_bridge::OpenHRP_StabilizerService_SupportPolygonVertices));
      }
      union {
        bool real;
        uint8_t base;
      } u_eefm_use_force_difference_control;
      u_eefm_use_force_difference_control.base = 0;
      u_eefm_use_force_difference_control.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->eefm_use_force_difference_control = u_eefm_use_force_difference_control.real;
      offset += sizeof(this->eefm_use_force_difference_control);
      union {
        bool real;
        uint8_t base;
      } u_eefm_use_swing_damping;
      u_eefm_use_swing_damping.base = 0;
      u_eefm_use_swing_damping.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->eefm_use_swing_damping = u_eefm_use_swing_damping.real;
      offset += sizeof(this->eefm_use_swing_damping);
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eefm_swing_damping_force_thre[i]));
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eefm_swing_damping_moment_thre[i]));
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eefm_swing_rot_damping_gain[i]));
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->eefm_swing_pos_damping_gain[i]));
      }
      offset += this->eefm_ee_forcemoment_distribution_weight.deserialize(inbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_st_algorithm;
      u_st_algorithm.base = 0;
      u_st_algorithm.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_algorithm.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_algorithm.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_algorithm.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_algorithm.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_algorithm.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_algorithm.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_algorithm.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_algorithm = u_st_algorithm.real;
      offset += sizeof(this->st_algorithm);
      union {
        int64_t real;
        uint64_t base;
      } u_controller_mode;
      u_controller_mode.base = 0;
      u_controller_mode.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_controller_mode.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_controller_mode.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_controller_mode.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_controller_mode.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_controller_mode.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_controller_mode.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_controller_mode.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->controller_mode = u_controller_mode.real;
      offset += sizeof(this->controller_mode);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->transition_time));
      uint32_t is_ik_enable_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      is_ik_enable_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      is_ik_enable_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      is_ik_enable_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->is_ik_enable_length);
      if(is_ik_enable_lengthT > is_ik_enable_length)
        this->is_ik_enable = (bool*)realloc(this->is_ik_enable, is_ik_enable_lengthT * sizeof(bool));
      is_ik_enable_length = is_ik_enable_lengthT;
      for( uint32_t i = 0; i < is_ik_enable_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_is_ik_enable;
      u_st_is_ik_enable.base = 0;
      u_st_is_ik_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_is_ik_enable = u_st_is_ik_enable.real;
      offset += sizeof(this->st_is_ik_enable);
        memcpy( &(this->is_ik_enable[i]), &(this->st_is_ik_enable), sizeof(bool));
      }
      uint32_t is_feedback_control_enable_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      is_feedback_control_enable_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      is_feedback_control_enable_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      is_feedback_control_enable_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->is_feedback_control_enable_length);
      if(is_feedback_control_enable_lengthT > is_feedback_control_enable_length)
        this->is_feedback_control_enable = (bool*)realloc(this->is_feedback_control_enable, is_feedback_control_enable_lengthT * sizeof(bool));
      is_feedback_control_enable_length = is_feedback_control_enable_lengthT;
      for( uint32_t i = 0; i < is_feedback_control_enable_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_is_feedback_control_enable;
      u_st_is_feedback_control_enable.base = 0;
      u_st_is_feedback_control_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_is_feedback_control_enable = u_st_is_feedback_control_enable.real;
      offset += sizeof(this->st_is_feedback_control_enable);
        memcpy( &(this->is_feedback_control_enable[i]), &(this->st_is_feedback_control_enable), sizeof(bool));
      }
      uint32_t is_zmp_calc_enable_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      is_zmp_calc_enable_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      is_zmp_calc_enable_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      is_zmp_calc_enable_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->is_zmp_calc_enable_length);
      if(is_zmp_calc_enable_lengthT > is_zmp_calc_enable_length)
        this->is_zmp_calc_enable = (bool*)realloc(this->is_zmp_calc_enable, is_zmp_calc_enable_lengthT * sizeof(bool));
      is_zmp_calc_enable_length = is_zmp_calc_enable_lengthT;
      for( uint32_t i = 0; i < is_zmp_calc_enable_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_is_zmp_calc_enable;
      u_st_is_zmp_calc_enable.base = 0;
      u_st_is_zmp_calc_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_is_zmp_calc_enable = u_st_is_zmp_calc_enable.real;
      offset += sizeof(this->st_is_zmp_calc_enable);
        memcpy( &(this->is_zmp_calc_enable[i]), &(this->st_is_zmp_calc_enable), sizeof(bool));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->cop_check_margin));
      for( uint32_t i = 0; i < 4; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->cp_check_margin[i]));
      }
      for( uint32_t i = 0; i < 2; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tilt_margin[i]));
      }
      for( uint32_t i = 0; i < 2; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ref_capture_point[i]));
      }
      for( uint32_t i = 0; i < 2; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->act_capture_point[i]));
      }
      for( uint32_t i = 0; i < 2; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->cp_offset[i]));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->contact_decision_threshold));
      offset += this->foot_origin_offset.deserialize(inbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_emergency_check_mode;
      u_emergency_check_mode.base = 0;
      u_emergency_check_mode.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_emergency_check_mode.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_emergency_check_mode.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_emergency_check_mode.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_emergency_check_mode.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_emergency_check_mode.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_emergency_check_mode.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_emergency_check_mode.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->emergency_check_mode = u_emergency_check_mode.real;
      offset += sizeof(this->emergency_check_mode);
      uint32_t end_effector_list_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      end_effector_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      end_effector_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      end_effector_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->end_effector_list_length);
      if(end_effector_list_lengthT > end_effector_list_length)
        this->end_effector_list = (hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep*)realloc(this->end_effector_list, end_effector_list_lengthT * sizeof(hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep));
      end_effector_list_length = end_effector_list_lengthT;
      for( uint32_t i = 0; i < end_effector_list_length; i++){
      offset += this->st_end_effector_list.deserialize(inbuffer + offset);
        memcpy( &(this->end_effector_list[i]), &(this->st_end_effector_list), sizeof(hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep));
      }
      union {
        bool real;
        uint8_t base;
      } u_is_estop_while_walking;
      u_is_estop_while_walking.base = 0;
      u_is_estop_while_walking.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_estop_while_walking = u_is_estop_while_walking.real;
      offset += sizeof(this->is_estop_while_walking);
      uint32_t ik_limb_parameters_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ik_limb_parameters_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ik_limb_parameters_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ik_limb_parameters_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->ik_limb_parameters_length);
      if(ik_limb_parameters_lengthT > ik_limb_parameters_length)
        this->ik_limb_parameters = (hrpsys_ros_bridge::OpenHRP_StabilizerService_IKLimbParameters*)realloc(this->ik_limb_parameters, ik_limb_parameters_lengthT * sizeof(hrpsys_ros_bridge::OpenHRP_StabilizerService_IKLimbParameters));
      ik_limb_parameters_length = ik_limb_parameters_lengthT;
      for( uint32_t i = 0; i < ik_limb_parameters_length; i++){
      offset += this->st_ik_limb_parameters.deserialize(inbuffer + offset);
        memcpy( &(this->ik_limb_parameters[i]), &(this->st_ik_limb_parameters), sizeof(hrpsys_ros_bridge::OpenHRP_StabilizerService_IKLimbParameters));
      }
      union {
        bool real;
        uint8_t base;
      } u_use_limb_stretch_avoidance;
      u_use_limb_stretch_avoidance.base = 0;
      u_use_limb_stretch_avoidance.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->use_limb_stretch_avoidance = u_use_limb_stretch_avoidance.real;
      offset += sizeof(this->use_limb_stretch_avoidance);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->limb_stretch_avoidance_time_const));
      for( uint32_t i = 0; i < 2; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->limb_stretch_avoidance_vlimit[i]));
      }
      uint32_t limb_length_margin_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      limb_length_margin_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      limb_length_margin_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      limb_length_margin_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->limb_length_margin_length);
      if(limb_length_margin_lengthT > limb_length_margin_length)
        this->limb_length_margin = (float*)realloc(this->limb_length_margin, limb_length_margin_lengthT * sizeof(float));
      limb_length_margin_length = limb_length_margin_lengthT;
      for( uint32_t i = 0; i < limb_length_margin_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_limb_length_margin));
        memcpy( &(this->limb_length_margin[i]), &(this->st_limb_length_margin), sizeof(float));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->detection_time_to_air));
      for( uint32_t i = 0; i < 2; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->root_rot_compensation_limit[i]));
      }
      union {
        bool real;
        uint8_t base;
      } u_use_zmp_truncation;
      u_use_zmp_truncation.base = 0;
      u_use_zmp_truncation.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->use_zmp_truncation = u_use_zmp_truncation.real;
      offset += sizeof(this->use_zmp_truncation);
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_StabilizerService_stParam"; };
    const char * getMD5(){ return "aa26b220e8557e45d84ee3fe6ead9a1d"; };

  };

}
#endif
