#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_IKLimbParameters_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_IKLimbParameters_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_AutoBalancerService_IKLimbParameters : public ros::Msg
  {
    public:
      uint32_t ik_optional_weight_vector_length;
      typedef float _ik_optional_weight_vector_type;
      _ik_optional_weight_vector_type st_ik_optional_weight_vector;
      _ik_optional_weight_vector_type * ik_optional_weight_vector;
      typedef float _sr_gain_type;
      _sr_gain_type sr_gain;
      typedef float _avoid_gain_type;
      _avoid_gain_type avoid_gain;
      typedef float _reference_gain_type;
      _reference_gain_type reference_gain;
      typedef float _manipulability_limit_type;
      _manipulability_limit_type manipulability_limit;

    OpenHRP_AutoBalancerService_IKLimbParameters():
      ik_optional_weight_vector_length(0), ik_optional_weight_vector(NULL),
      sr_gain(0),
      avoid_gain(0),
      reference_gain(0),
      manipulability_limit(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->ik_optional_weight_vector_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ik_optional_weight_vector_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ik_optional_weight_vector_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ik_optional_weight_vector_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ik_optional_weight_vector_length);
      for( uint32_t i = 0; i < ik_optional_weight_vector_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->ik_optional_weight_vector[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->sr_gain);
      offset += serializeAvrFloat64(outbuffer + offset, this->avoid_gain);
      offset += serializeAvrFloat64(outbuffer + offset, this->reference_gain);
      offset += serializeAvrFloat64(outbuffer + offset, this->manipulability_limit);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
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
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->sr_gain));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->avoid_gain));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->reference_gain));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->manipulability_limit));
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_IKLimbParameters"; };
    const char * getMD5(){ return "970ca9b7a300937198127b6ecce51930"; };

  };

}
#endif
