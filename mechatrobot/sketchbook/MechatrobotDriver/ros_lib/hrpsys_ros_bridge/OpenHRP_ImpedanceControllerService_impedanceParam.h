#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_ImpedanceControllerService_impedanceParam_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_ImpedanceControllerService_impedanceParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_ImpedanceControllerService_impedanceParam : public ros::Msg
  {
    public:
      typedef float _M_p_type;
      _M_p_type M_p;
      typedef float _D_p_type;
      _D_p_type D_p;
      typedef float _K_p_type;
      _K_p_type K_p;
      typedef float _M_r_type;
      _M_r_type M_r;
      typedef float _D_r_type;
      _D_r_type D_r;
      typedef float _K_r_type;
      _K_r_type K_r;
      float force_gain[3];
      float moment_gain[3];
      typedef float _sr_gain_type;
      _sr_gain_type sr_gain;
      typedef float _avoid_gain_type;
      _avoid_gain_type avoid_gain;
      typedef float _reference_gain_type;
      _reference_gain_type reference_gain;
      typedef float _manipulability_limit_type;
      _manipulability_limit_type manipulability_limit;
      typedef int64_t _controller_mode_type;
      _controller_mode_type controller_mode;
      uint32_t ik_optional_weight_vector_length;
      typedef float _ik_optional_weight_vector_type;
      _ik_optional_weight_vector_type st_ik_optional_weight_vector;
      _ik_optional_weight_vector_type * ik_optional_weight_vector;
      typedef bool _use_sh_base_pos_rpy_type;
      _use_sh_base_pos_rpy_type use_sh_base_pos_rpy;

    OpenHRP_ImpedanceControllerService_impedanceParam():
      M_p(0),
      D_p(0),
      K_p(0),
      M_r(0),
      D_r(0),
      K_r(0),
      force_gain(),
      moment_gain(),
      sr_gain(0),
      avoid_gain(0),
      reference_gain(0),
      manipulability_limit(0),
      controller_mode(0),
      ik_optional_weight_vector_length(0), ik_optional_weight_vector(NULL),
      use_sh_base_pos_rpy(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->M_p);
      offset += serializeAvrFloat64(outbuffer + offset, this->D_p);
      offset += serializeAvrFloat64(outbuffer + offset, this->K_p);
      offset += serializeAvrFloat64(outbuffer + offset, this->M_r);
      offset += serializeAvrFloat64(outbuffer + offset, this->D_r);
      offset += serializeAvrFloat64(outbuffer + offset, this->K_r);
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->force_gain[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->moment_gain[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->sr_gain);
      offset += serializeAvrFloat64(outbuffer + offset, this->avoid_gain);
      offset += serializeAvrFloat64(outbuffer + offset, this->reference_gain);
      offset += serializeAvrFloat64(outbuffer + offset, this->manipulability_limit);
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
      *(outbuffer + offset + 0) = (this->ik_optional_weight_vector_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ik_optional_weight_vector_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ik_optional_weight_vector_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ik_optional_weight_vector_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ik_optional_weight_vector_length);
      for( uint32_t i = 0; i < ik_optional_weight_vector_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->ik_optional_weight_vector[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_use_sh_base_pos_rpy;
      u_use_sh_base_pos_rpy.real = this->use_sh_base_pos_rpy;
      *(outbuffer + offset + 0) = (u_use_sh_base_pos_rpy.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->use_sh_base_pos_rpy);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->M_p));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->D_p));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->K_p));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->M_r));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->D_r));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->K_r));
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->force_gain[i]));
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->moment_gain[i]));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->sr_gain));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->avoid_gain));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->reference_gain));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->manipulability_limit));
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
      uint32_t ik_optional_weight_vector_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ik_optional_weight_vector_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ik_optional_weight_vector_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ik_optional_weight_vector_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->ik_optional_weight_vector_length);
      if(ik_optional_weight_vector_lengthT > ik_optional_weight_vector_length)
        this->ik_optional_weight_vector = (float*)realloc(this->ik_optional_weight_vector, ik_optional_weight_vector_lengthT * sizeof(float));
      ik_optional_weight_vector_length = ik_optional_weight_vector_lengthT;
      for( uint32_t i = 0; i < ik_optional_weight_vector_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_ik_optional_weight_vector));
        memcpy( &(this->ik_optional_weight_vector[i]), &(this->st_ik_optional_weight_vector), sizeof(float));
      }
      union {
        bool real;
        uint8_t base;
      } u_use_sh_base_pos_rpy;
      u_use_sh_base_pos_rpy.base = 0;
      u_use_sh_base_pos_rpy.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->use_sh_base_pos_rpy = u_use_sh_base_pos_rpy.real;
      offset += sizeof(this->use_sh_base_pos_rpy);
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_ImpedanceControllerService_impedanceParam"; };
    const char * getMD5(){ return "93910157f4c229ccb0ff5677c4006630"; };

  };

}
#endif
