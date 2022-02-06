#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_GaitGeneratorParam_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_GaitGeneratorParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Float64MultiArray.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_AutoBalancerService_GaitGeneratorParam : public ros::Msg
  {
    public:
      typedef float _default_step_time_type;
      _default_step_time_type default_step_time;
      typedef float _default_step_height_type;
      _default_step_height_type default_step_height;
      typedef float _default_double_support_ratio_type;
      _default_double_support_ratio_type default_double_support_ratio;
      typedef float _default_double_support_ratio_before_type;
      _default_double_support_ratio_before_type default_double_support_ratio_before;
      typedef float _default_double_support_ratio_after_type;
      _default_double_support_ratio_after_type default_double_support_ratio_after;
      typedef float _default_double_support_static_ratio_type;
      _default_double_support_static_ratio_type default_double_support_static_ratio;
      typedef float _default_double_support_static_ratio_before_type;
      _default_double_support_static_ratio_before_type default_double_support_static_ratio_before;
      typedef float _default_double_support_static_ratio_after_type;
      _default_double_support_static_ratio_after_type default_double_support_static_ratio_after;
      typedef float _default_double_support_ratio_swing_before_type;
      _default_double_support_ratio_swing_before_type default_double_support_ratio_swing_before;
      typedef float _default_double_support_ratio_swing_after_type;
      _default_double_support_ratio_swing_after_type default_double_support_ratio_swing_after;
      float stride_parameter[6];
      float stride_limitation_for_circle_type[5];
      typedef int64_t _default_orbit_type_type;
      _default_orbit_type_type default_orbit_type;
      typedef float _swing_trajectory_delay_time_offset_type;
      _swing_trajectory_delay_time_offset_type swing_trajectory_delay_time_offset;
      typedef float _swing_trajectory_final_distance_weight_type;
      _swing_trajectory_final_distance_weight_type swing_trajectory_final_distance_weight;
      float stair_trajectory_way_point_offset[3];
      float cycloid_delay_kick_point_offset[3];
      typedef float _swing_trajectory_time_offset_xy2z_type;
      _swing_trajectory_time_offset_xy2z_type swing_trajectory_time_offset_xy2z;
      typedef float _gravitational_acceleration_type;
      _gravitational_acceleration_type gravitational_acceleration;
      typedef float _toe_pos_offset_x_type;
      _toe_pos_offset_x_type toe_pos_offset_x;
      typedef float _heel_pos_offset_x_type;
      _heel_pos_offset_x_type heel_pos_offset_x;
      typedef float _toe_zmp_offset_x_type;
      _toe_zmp_offset_x_type toe_zmp_offset_x;
      typedef float _heel_zmp_offset_x_type;
      _heel_zmp_offset_x_type heel_zmp_offset_x;
      typedef float _toe_angle_type;
      _toe_angle_type toe_angle;
      typedef float _heel_angle_type;
      _heel_angle_type heel_angle;
      typedef float _toe_check_thre_type;
      _toe_check_thre_type toe_check_thre;
      typedef float _heel_check_thre_type;
      _heel_check_thre_type heel_check_thre;
      uint32_t toe_heel_phase_ratio_length;
      typedef float _toe_heel_phase_ratio_type;
      _toe_heel_phase_ratio_type st_toe_heel_phase_ratio;
      _toe_heel_phase_ratio_type * toe_heel_phase_ratio;
      typedef bool _use_toe_joint_type;
      _use_toe_joint_type use_toe_joint;
      typedef bool _use_toe_heel_transition_type;
      _use_toe_heel_transition_type use_toe_heel_transition;
      typedef bool _use_toe_heel_auto_set_type;
      _use_toe_heel_auto_set_type use_toe_heel_auto_set;
      float zmp_weight_map[4];
      typedef std_msgs::Float64MultiArray _leg_default_translate_pos_type;
      _leg_default_translate_pos_type leg_default_translate_pos;
      typedef int32_t _optional_go_pos_finalize_footstep_num_type;
      _optional_go_pos_finalize_footstep_num_type optional_go_pos_finalize_footstep_num;
      typedef int32_t _overwritable_footstep_index_offset_type;
      _overwritable_footstep_index_offset_type overwritable_footstep_index_offset;
      float overwritable_stride_limitation[5];
      typedef bool _use_stride_limitation_type;
      _use_stride_limitation_type use_stride_limitation;
      typedef int64_t _stride_limitation_type_type;
      _stride_limitation_type_type stride_limitation_type;
      float leg_margin[4];
      typedef float _footstep_modification_gain_type;
      _footstep_modification_gain_type footstep_modification_gain;
      typedef bool _modify_footsteps_type;
      _modify_footsteps_type modify_footsteps;
      float cp_check_margin[2];
      typedef float _margin_time_ratio_type;
      _margin_time_ratio_type margin_time_ratio;

    OpenHRP_AutoBalancerService_GaitGeneratorParam():
      default_step_time(0),
      default_step_height(0),
      default_double_support_ratio(0),
      default_double_support_ratio_before(0),
      default_double_support_ratio_after(0),
      default_double_support_static_ratio(0),
      default_double_support_static_ratio_before(0),
      default_double_support_static_ratio_after(0),
      default_double_support_ratio_swing_before(0),
      default_double_support_ratio_swing_after(0),
      stride_parameter(),
      stride_limitation_for_circle_type(),
      default_orbit_type(0),
      swing_trajectory_delay_time_offset(0),
      swing_trajectory_final_distance_weight(0),
      stair_trajectory_way_point_offset(),
      cycloid_delay_kick_point_offset(),
      swing_trajectory_time_offset_xy2z(0),
      gravitational_acceleration(0),
      toe_pos_offset_x(0),
      heel_pos_offset_x(0),
      toe_zmp_offset_x(0),
      heel_zmp_offset_x(0),
      toe_angle(0),
      heel_angle(0),
      toe_check_thre(0),
      heel_check_thre(0),
      toe_heel_phase_ratio_length(0), toe_heel_phase_ratio(NULL),
      use_toe_joint(0),
      use_toe_heel_transition(0),
      use_toe_heel_auto_set(0),
      zmp_weight_map(),
      leg_default_translate_pos(),
      optional_go_pos_finalize_footstep_num(0),
      overwritable_footstep_index_offset(0),
      overwritable_stride_limitation(),
      use_stride_limitation(0),
      stride_limitation_type(0),
      leg_margin(),
      footstep_modification_gain(0),
      modify_footsteps(0),
      cp_check_margin(),
      margin_time_ratio(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->default_step_time);
      offset += serializeAvrFloat64(outbuffer + offset, this->default_step_height);
      offset += serializeAvrFloat64(outbuffer + offset, this->default_double_support_ratio);
      offset += serializeAvrFloat64(outbuffer + offset, this->default_double_support_ratio_before);
      offset += serializeAvrFloat64(outbuffer + offset, this->default_double_support_ratio_after);
      offset += serializeAvrFloat64(outbuffer + offset, this->default_double_support_static_ratio);
      offset += serializeAvrFloat64(outbuffer + offset, this->default_double_support_static_ratio_before);
      offset += serializeAvrFloat64(outbuffer + offset, this->default_double_support_static_ratio_after);
      offset += serializeAvrFloat64(outbuffer + offset, this->default_double_support_ratio_swing_before);
      offset += serializeAvrFloat64(outbuffer + offset, this->default_double_support_ratio_swing_after);
      for( uint32_t i = 0; i < 6; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->stride_parameter[i]);
      }
      for( uint32_t i = 0; i < 5; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->stride_limitation_for_circle_type[i]);
      }
      union {
        int64_t real;
        uint64_t base;
      } u_default_orbit_type;
      u_default_orbit_type.real = this->default_orbit_type;
      *(outbuffer + offset + 0) = (u_default_orbit_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_default_orbit_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_default_orbit_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_default_orbit_type.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_default_orbit_type.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_default_orbit_type.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_default_orbit_type.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_default_orbit_type.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->default_orbit_type);
      offset += serializeAvrFloat64(outbuffer + offset, this->swing_trajectory_delay_time_offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->swing_trajectory_final_distance_weight);
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->stair_trajectory_way_point_offset[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->cycloid_delay_kick_point_offset[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->swing_trajectory_time_offset_xy2z);
      offset += serializeAvrFloat64(outbuffer + offset, this->gravitational_acceleration);
      offset += serializeAvrFloat64(outbuffer + offset, this->toe_pos_offset_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->heel_pos_offset_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->toe_zmp_offset_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->heel_zmp_offset_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->toe_angle);
      offset += serializeAvrFloat64(outbuffer + offset, this->heel_angle);
      offset += serializeAvrFloat64(outbuffer + offset, this->toe_check_thre);
      offset += serializeAvrFloat64(outbuffer + offset, this->heel_check_thre);
      *(outbuffer + offset + 0) = (this->toe_heel_phase_ratio_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->toe_heel_phase_ratio_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->toe_heel_phase_ratio_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->toe_heel_phase_ratio_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->toe_heel_phase_ratio_length);
      for( uint32_t i = 0; i < toe_heel_phase_ratio_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->toe_heel_phase_ratio[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_use_toe_joint;
      u_use_toe_joint.real = this->use_toe_joint;
      *(outbuffer + offset + 0) = (u_use_toe_joint.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->use_toe_joint);
      union {
        bool real;
        uint8_t base;
      } u_use_toe_heel_transition;
      u_use_toe_heel_transition.real = this->use_toe_heel_transition;
      *(outbuffer + offset + 0) = (u_use_toe_heel_transition.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->use_toe_heel_transition);
      union {
        bool real;
        uint8_t base;
      } u_use_toe_heel_auto_set;
      u_use_toe_heel_auto_set.real = this->use_toe_heel_auto_set;
      *(outbuffer + offset + 0) = (u_use_toe_heel_auto_set.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->use_toe_heel_auto_set);
      for( uint32_t i = 0; i < 4; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->zmp_weight_map[i]);
      }
      offset += this->leg_default_translate_pos.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_optional_go_pos_finalize_footstep_num;
      u_optional_go_pos_finalize_footstep_num.real = this->optional_go_pos_finalize_footstep_num;
      *(outbuffer + offset + 0) = (u_optional_go_pos_finalize_footstep_num.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_optional_go_pos_finalize_footstep_num.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_optional_go_pos_finalize_footstep_num.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_optional_go_pos_finalize_footstep_num.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->optional_go_pos_finalize_footstep_num);
      union {
        int32_t real;
        uint32_t base;
      } u_overwritable_footstep_index_offset;
      u_overwritable_footstep_index_offset.real = this->overwritable_footstep_index_offset;
      *(outbuffer + offset + 0) = (u_overwritable_footstep_index_offset.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_overwritable_footstep_index_offset.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_overwritable_footstep_index_offset.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_overwritable_footstep_index_offset.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->overwritable_footstep_index_offset);
      for( uint32_t i = 0; i < 5; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->overwritable_stride_limitation[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_use_stride_limitation;
      u_use_stride_limitation.real = this->use_stride_limitation;
      *(outbuffer + offset + 0) = (u_use_stride_limitation.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->use_stride_limitation);
      union {
        int64_t real;
        uint64_t base;
      } u_stride_limitation_type;
      u_stride_limitation_type.real = this->stride_limitation_type;
      *(outbuffer + offset + 0) = (u_stride_limitation_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_stride_limitation_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_stride_limitation_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_stride_limitation_type.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_stride_limitation_type.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_stride_limitation_type.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_stride_limitation_type.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_stride_limitation_type.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->stride_limitation_type);
      for( uint32_t i = 0; i < 4; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->leg_margin[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->footstep_modification_gain);
      union {
        bool real;
        uint8_t base;
      } u_modify_footsteps;
      u_modify_footsteps.real = this->modify_footsteps;
      *(outbuffer + offset + 0) = (u_modify_footsteps.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->modify_footsteps);
      for( uint32_t i = 0; i < 2; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->cp_check_margin[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->margin_time_ratio);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->default_step_time));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->default_step_height));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->default_double_support_ratio));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->default_double_support_ratio_before));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->default_double_support_ratio_after));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->default_double_support_static_ratio));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->default_double_support_static_ratio_before));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->default_double_support_static_ratio_after));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->default_double_support_ratio_swing_before));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->default_double_support_ratio_swing_after));
      for( uint32_t i = 0; i < 6; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->stride_parameter[i]));
      }
      for( uint32_t i = 0; i < 5; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->stride_limitation_for_circle_type[i]));
      }
      union {
        int64_t real;
        uint64_t base;
      } u_default_orbit_type;
      u_default_orbit_type.base = 0;
      u_default_orbit_type.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_default_orbit_type.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_default_orbit_type.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_default_orbit_type.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_default_orbit_type.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_default_orbit_type.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_default_orbit_type.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_default_orbit_type.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->default_orbit_type = u_default_orbit_type.real;
      offset += sizeof(this->default_orbit_type);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->swing_trajectory_delay_time_offset));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->swing_trajectory_final_distance_weight));
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->stair_trajectory_way_point_offset[i]));
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->cycloid_delay_kick_point_offset[i]));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->swing_trajectory_time_offset_xy2z));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gravitational_acceleration));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->toe_pos_offset_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->heel_pos_offset_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->toe_zmp_offset_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->heel_zmp_offset_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->toe_angle));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->heel_angle));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->toe_check_thre));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->heel_check_thre));
      uint32_t toe_heel_phase_ratio_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      toe_heel_phase_ratio_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      toe_heel_phase_ratio_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      toe_heel_phase_ratio_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->toe_heel_phase_ratio_length);
      if(toe_heel_phase_ratio_lengthT > toe_heel_phase_ratio_length)
        this->toe_heel_phase_ratio = (float*)realloc(this->toe_heel_phase_ratio, toe_heel_phase_ratio_lengthT * sizeof(float));
      toe_heel_phase_ratio_length = toe_heel_phase_ratio_lengthT;
      for( uint32_t i = 0; i < toe_heel_phase_ratio_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_toe_heel_phase_ratio));
        memcpy( &(this->toe_heel_phase_ratio[i]), &(this->st_toe_heel_phase_ratio), sizeof(float));
      }
      union {
        bool real;
        uint8_t base;
      } u_use_toe_joint;
      u_use_toe_joint.base = 0;
      u_use_toe_joint.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->use_toe_joint = u_use_toe_joint.real;
      offset += sizeof(this->use_toe_joint);
      union {
        bool real;
        uint8_t base;
      } u_use_toe_heel_transition;
      u_use_toe_heel_transition.base = 0;
      u_use_toe_heel_transition.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->use_toe_heel_transition = u_use_toe_heel_transition.real;
      offset += sizeof(this->use_toe_heel_transition);
      union {
        bool real;
        uint8_t base;
      } u_use_toe_heel_auto_set;
      u_use_toe_heel_auto_set.base = 0;
      u_use_toe_heel_auto_set.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->use_toe_heel_auto_set = u_use_toe_heel_auto_set.real;
      offset += sizeof(this->use_toe_heel_auto_set);
      for( uint32_t i = 0; i < 4; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->zmp_weight_map[i]));
      }
      offset += this->leg_default_translate_pos.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_optional_go_pos_finalize_footstep_num;
      u_optional_go_pos_finalize_footstep_num.base = 0;
      u_optional_go_pos_finalize_footstep_num.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_optional_go_pos_finalize_footstep_num.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_optional_go_pos_finalize_footstep_num.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_optional_go_pos_finalize_footstep_num.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->optional_go_pos_finalize_footstep_num = u_optional_go_pos_finalize_footstep_num.real;
      offset += sizeof(this->optional_go_pos_finalize_footstep_num);
      union {
        int32_t real;
        uint32_t base;
      } u_overwritable_footstep_index_offset;
      u_overwritable_footstep_index_offset.base = 0;
      u_overwritable_footstep_index_offset.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_overwritable_footstep_index_offset.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_overwritable_footstep_index_offset.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_overwritable_footstep_index_offset.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->overwritable_footstep_index_offset = u_overwritable_footstep_index_offset.real;
      offset += sizeof(this->overwritable_footstep_index_offset);
      for( uint32_t i = 0; i < 5; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->overwritable_stride_limitation[i]));
      }
      union {
        bool real;
        uint8_t base;
      } u_use_stride_limitation;
      u_use_stride_limitation.base = 0;
      u_use_stride_limitation.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->use_stride_limitation = u_use_stride_limitation.real;
      offset += sizeof(this->use_stride_limitation);
      union {
        int64_t real;
        uint64_t base;
      } u_stride_limitation_type;
      u_stride_limitation_type.base = 0;
      u_stride_limitation_type.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_stride_limitation_type.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_stride_limitation_type.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_stride_limitation_type.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_stride_limitation_type.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_stride_limitation_type.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_stride_limitation_type.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_stride_limitation_type.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->stride_limitation_type = u_stride_limitation_type.real;
      offset += sizeof(this->stride_limitation_type);
      for( uint32_t i = 0; i < 4; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->leg_margin[i]));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->footstep_modification_gain));
      union {
        bool real;
        uint8_t base;
      } u_modify_footsteps;
      u_modify_footsteps.base = 0;
      u_modify_footsteps.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->modify_footsteps = u_modify_footsteps.real;
      offset += sizeof(this->modify_footsteps);
      for( uint32_t i = 0; i < 2; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->cp_check_margin[i]));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->margin_time_ratio));
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_GaitGeneratorParam"; };
    const char * getMD5(){ return "9fcee90f7bbd41cf165451c6fc29aea4"; };

  };

}
#endif
