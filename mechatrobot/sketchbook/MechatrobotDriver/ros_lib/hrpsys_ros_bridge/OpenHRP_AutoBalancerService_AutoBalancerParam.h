#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_AutoBalancerParam_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_AutoBalancerParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Float64MultiArray.h"
#include "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_Footstep.h"
#include "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_IKLimbParameters.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_AutoBalancerService_AutoBalancerParam : public ros::Msg
  {
    public:
      typedef std_msgs::Float64MultiArray _default_zmp_offsets_type;
      _default_zmp_offsets_type default_zmp_offsets;
      typedef float _move_base_gain_type;
      _move_base_gain_type move_base_gain;
      typedef int64_t _controller_mode_type;
      _controller_mode_type controller_mode;
      typedef int64_t _use_force_mode_type;
      _use_force_mode_type use_force_mode;
      typedef bool _graspless_manip_mode_type;
      _graspless_manip_mode_type graspless_manip_mode;
      typedef const char* _graspless_manip_arm_type;
      _graspless_manip_arm_type graspless_manip_arm;
      float graspless_manip_p_gain[3];
      float graspless_manip_reference_trans_pos[3];
      float graspless_manip_reference_trans_rot[4];
      typedef float _transition_time_type;
      _transition_time_type transition_time;
      typedef float _zmp_transition_time_type;
      _zmp_transition_time_type zmp_transition_time;
      typedef float _adjust_footstep_transition_time_type;
      _adjust_footstep_transition_time_type adjust_footstep_transition_time;
      uint32_t leg_names_length;
      typedef char* _leg_names_type;
      _leg_names_type st_leg_names;
      _leg_names_type * leg_names;
      typedef bool _has_ik_failed_type;
      _has_ik_failed_type has_ik_failed;
      typedef float _pos_ik_thre_type;
      _pos_ik_thre_type pos_ik_thre;
      typedef float _rot_ik_thre_type;
      _rot_ik_thre_type rot_ik_thre;
      typedef bool _is_hand_fix_mode_type;
      _is_hand_fix_mode_type is_hand_fix_mode;
      uint32_t end_effector_list_length;
      typedef hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep _end_effector_list_type;
      _end_effector_list_type st_end_effector_list;
      _end_effector_list_type * end_effector_list;
      typedef int64_t _default_gait_type_type;
      _default_gait_type_type default_gait_type;
      uint32_t ik_limb_parameters_length;
      typedef hrpsys_ros_bridge::OpenHRP_AutoBalancerService_IKLimbParameters _ik_limb_parameters_type;
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
      typedef const char* _additional_force_applied_link_name_type;
      _additional_force_applied_link_name_type additional_force_applied_link_name;
      float additional_force_applied_point_offset[3];

    OpenHRP_AutoBalancerService_AutoBalancerParam():
      default_zmp_offsets(),
      move_base_gain(0),
      controller_mode(0),
      use_force_mode(0),
      graspless_manip_mode(0),
      graspless_manip_arm(""),
      graspless_manip_p_gain(),
      graspless_manip_reference_trans_pos(),
      graspless_manip_reference_trans_rot(),
      transition_time(0),
      zmp_transition_time(0),
      adjust_footstep_transition_time(0),
      leg_names_length(0), leg_names(NULL),
      has_ik_failed(0),
      pos_ik_thre(0),
      rot_ik_thre(0),
      is_hand_fix_mode(0),
      end_effector_list_length(0), end_effector_list(NULL),
      default_gait_type(0),
      ik_limb_parameters_length(0), ik_limb_parameters(NULL),
      use_limb_stretch_avoidance(0),
      limb_stretch_avoidance_time_const(0),
      limb_stretch_avoidance_vlimit(),
      limb_length_margin_length(0), limb_length_margin(NULL),
      additional_force_applied_link_name(""),
      additional_force_applied_point_offset()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->default_zmp_offsets.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->move_base_gain);
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
      union {
        int64_t real;
        uint64_t base;
      } u_use_force_mode;
      u_use_force_mode.real = this->use_force_mode;
      *(outbuffer + offset + 0) = (u_use_force_mode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_use_force_mode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_use_force_mode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_use_force_mode.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_use_force_mode.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_use_force_mode.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_use_force_mode.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_use_force_mode.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->use_force_mode);
      union {
        bool real;
        uint8_t base;
      } u_graspless_manip_mode;
      u_graspless_manip_mode.real = this->graspless_manip_mode;
      *(outbuffer + offset + 0) = (u_graspless_manip_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->graspless_manip_mode);
      uint32_t length_graspless_manip_arm = strlen(this->graspless_manip_arm);
      varToArr(outbuffer + offset, length_graspless_manip_arm);
      offset += 4;
      memcpy(outbuffer + offset, this->graspless_manip_arm, length_graspless_manip_arm);
      offset += length_graspless_manip_arm;
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->graspless_manip_p_gain[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->graspless_manip_reference_trans_pos[i]);
      }
      for( uint32_t i = 0; i < 4; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->graspless_manip_reference_trans_rot[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->transition_time);
      offset += serializeAvrFloat64(outbuffer + offset, this->zmp_transition_time);
      offset += serializeAvrFloat64(outbuffer + offset, this->adjust_footstep_transition_time);
      *(outbuffer + offset + 0) = (this->leg_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->leg_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->leg_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->leg_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->leg_names_length);
      for( uint32_t i = 0; i < leg_names_length; i++){
      uint32_t length_leg_namesi = strlen(this->leg_names[i]);
      varToArr(outbuffer + offset, length_leg_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->leg_names[i], length_leg_namesi);
      offset += length_leg_namesi;
      }
      union {
        bool real;
        uint8_t base;
      } u_has_ik_failed;
      u_has_ik_failed.real = this->has_ik_failed;
      *(outbuffer + offset + 0) = (u_has_ik_failed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_ik_failed);
      offset += serializeAvrFloat64(outbuffer + offset, this->pos_ik_thre);
      offset += serializeAvrFloat64(outbuffer + offset, this->rot_ik_thre);
      union {
        bool real;
        uint8_t base;
      } u_is_hand_fix_mode;
      u_is_hand_fix_mode.real = this->is_hand_fix_mode;
      *(outbuffer + offset + 0) = (u_is_hand_fix_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_hand_fix_mode);
      *(outbuffer + offset + 0) = (this->end_effector_list_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->end_effector_list_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->end_effector_list_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->end_effector_list_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->end_effector_list_length);
      for( uint32_t i = 0; i < end_effector_list_length; i++){
      offset += this->end_effector_list[i].serialize(outbuffer + offset);
      }
      union {
        int64_t real;
        uint64_t base;
      } u_default_gait_type;
      u_default_gait_type.real = this->default_gait_type;
      *(outbuffer + offset + 0) = (u_default_gait_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_default_gait_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_default_gait_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_default_gait_type.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_default_gait_type.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_default_gait_type.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_default_gait_type.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_default_gait_type.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->default_gait_type);
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
      uint32_t length_additional_force_applied_link_name = strlen(this->additional_force_applied_link_name);
      varToArr(outbuffer + offset, length_additional_force_applied_link_name);
      offset += 4;
      memcpy(outbuffer + offset, this->additional_force_applied_link_name, length_additional_force_applied_link_name);
      offset += length_additional_force_applied_link_name;
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->additional_force_applied_point_offset[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->default_zmp_offsets.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->move_base_gain));
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
      union {
        int64_t real;
        uint64_t base;
      } u_use_force_mode;
      u_use_force_mode.base = 0;
      u_use_force_mode.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_use_force_mode.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_use_force_mode.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_use_force_mode.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_use_force_mode.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_use_force_mode.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_use_force_mode.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_use_force_mode.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->use_force_mode = u_use_force_mode.real;
      offset += sizeof(this->use_force_mode);
      union {
        bool real;
        uint8_t base;
      } u_graspless_manip_mode;
      u_graspless_manip_mode.base = 0;
      u_graspless_manip_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->graspless_manip_mode = u_graspless_manip_mode.real;
      offset += sizeof(this->graspless_manip_mode);
      uint32_t length_graspless_manip_arm;
      arrToVar(length_graspless_manip_arm, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_graspless_manip_arm; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_graspless_manip_arm-1]=0;
      this->graspless_manip_arm = (char *)(inbuffer + offset-1);
      offset += length_graspless_manip_arm;
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->graspless_manip_p_gain[i]));
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->graspless_manip_reference_trans_pos[i]));
      }
      for( uint32_t i = 0; i < 4; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->graspless_manip_reference_trans_rot[i]));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->transition_time));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->zmp_transition_time));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->adjust_footstep_transition_time));
      uint32_t leg_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      leg_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      leg_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      leg_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->leg_names_length);
      if(leg_names_lengthT > leg_names_length)
        this->leg_names = (char**)realloc(this->leg_names, leg_names_lengthT * sizeof(char*));
      leg_names_length = leg_names_lengthT;
      for( uint32_t i = 0; i < leg_names_length; i++){
      uint32_t length_st_leg_names;
      arrToVar(length_st_leg_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_leg_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_leg_names-1]=0;
      this->st_leg_names = (char *)(inbuffer + offset-1);
      offset += length_st_leg_names;
        memcpy( &(this->leg_names[i]), &(this->st_leg_names), sizeof(char*));
      }
      union {
        bool real;
        uint8_t base;
      } u_has_ik_failed;
      u_has_ik_failed.base = 0;
      u_has_ik_failed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_ik_failed = u_has_ik_failed.real;
      offset += sizeof(this->has_ik_failed);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pos_ik_thre));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rot_ik_thre));
      union {
        bool real;
        uint8_t base;
      } u_is_hand_fix_mode;
      u_is_hand_fix_mode.base = 0;
      u_is_hand_fix_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_hand_fix_mode = u_is_hand_fix_mode.real;
      offset += sizeof(this->is_hand_fix_mode);
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
        int64_t real;
        uint64_t base;
      } u_default_gait_type;
      u_default_gait_type.base = 0;
      u_default_gait_type.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_default_gait_type.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_default_gait_type.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_default_gait_type.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_default_gait_type.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_default_gait_type.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_default_gait_type.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_default_gait_type.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->default_gait_type = u_default_gait_type.real;
      offset += sizeof(this->default_gait_type);
      uint32_t ik_limb_parameters_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ik_limb_parameters_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ik_limb_parameters_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ik_limb_parameters_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->ik_limb_parameters_length);
      if(ik_limb_parameters_lengthT > ik_limb_parameters_length)
        this->ik_limb_parameters = (hrpsys_ros_bridge::OpenHRP_AutoBalancerService_IKLimbParameters*)realloc(this->ik_limb_parameters, ik_limb_parameters_lengthT * sizeof(hrpsys_ros_bridge::OpenHRP_AutoBalancerService_IKLimbParameters));
      ik_limb_parameters_length = ik_limb_parameters_lengthT;
      for( uint32_t i = 0; i < ik_limb_parameters_length; i++){
      offset += this->st_ik_limb_parameters.deserialize(inbuffer + offset);
        memcpy( &(this->ik_limb_parameters[i]), &(this->st_ik_limb_parameters), sizeof(hrpsys_ros_bridge::OpenHRP_AutoBalancerService_IKLimbParameters));
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
      uint32_t length_additional_force_applied_link_name;
      arrToVar(length_additional_force_applied_link_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_additional_force_applied_link_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_additional_force_applied_link_name-1]=0;
      this->additional_force_applied_link_name = (char *)(inbuffer + offset-1);
      offset += length_additional_force_applied_link_name;
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->additional_force_applied_point_offset[i]));
      }
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_AutoBalancerParam"; };
    const char * getMD5(){ return "9b4eedd57e7a663df085db0496a36f71"; };

  };

}
#endif
