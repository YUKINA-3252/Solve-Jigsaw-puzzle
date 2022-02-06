#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_StateHolderService_Command_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_StateHolderService_Command_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_StateHolderService_Command : public ros::Msg
  {
    public:
      uint32_t jointRefs_length;
      typedef float _jointRefs_type;
      _jointRefs_type st_jointRefs;
      _jointRefs_type * jointRefs;
      uint32_t baseTransform_length;
      typedef float _baseTransform_type;
      _baseTransform_type st_baseTransform;
      _baseTransform_type * baseTransform;
      uint32_t zmp_length;
      typedef float _zmp_type;
      _zmp_type st_zmp;
      _zmp_type * zmp;

    OpenHRP_StateHolderService_Command():
      jointRefs_length(0), jointRefs(NULL),
      baseTransform_length(0), baseTransform(NULL),
      zmp_length(0), zmp(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->jointRefs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->jointRefs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->jointRefs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->jointRefs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->jointRefs_length);
      for( uint32_t i = 0; i < jointRefs_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->jointRefs[i]);
      }
      *(outbuffer + offset + 0) = (this->baseTransform_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->baseTransform_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->baseTransform_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->baseTransform_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->baseTransform_length);
      for( uint32_t i = 0; i < baseTransform_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->baseTransform[i]);
      }
      *(outbuffer + offset + 0) = (this->zmp_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->zmp_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->zmp_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->zmp_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->zmp_length);
      for( uint32_t i = 0; i < zmp_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->zmp[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t jointRefs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      jointRefs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      jointRefs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      jointRefs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->jointRefs_length);
      if(jointRefs_lengthT > jointRefs_length)
        this->jointRefs = (float*)realloc(this->jointRefs, jointRefs_lengthT * sizeof(float));
      jointRefs_length = jointRefs_lengthT;
      for( uint32_t i = 0; i < jointRefs_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_jointRefs));
        memcpy( &(this->jointRefs[i]), &(this->st_jointRefs), sizeof(float));
      }
      uint32_t baseTransform_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      baseTransform_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      baseTransform_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      baseTransform_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->baseTransform_length);
      if(baseTransform_lengthT > baseTransform_length)
        this->baseTransform = (float*)realloc(this->baseTransform, baseTransform_lengthT * sizeof(float));
      baseTransform_length = baseTransform_lengthT;
      for( uint32_t i = 0; i < baseTransform_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_baseTransform));
        memcpy( &(this->baseTransform[i]), &(this->st_baseTransform), sizeof(float));
      }
      uint32_t zmp_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      zmp_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      zmp_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      zmp_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->zmp_length);
      if(zmp_lengthT > zmp_length)
        this->zmp = (float*)realloc(this->zmp, zmp_lengthT * sizeof(float));
      zmp_length = zmp_lengthT;
      for( uint32_t i = 0; i < zmp_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_zmp));
        memcpy( &(this->zmp[i]), &(this->st_zmp), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_StateHolderService_Command"; };
    const char * getMD5(){ return "c456a517c9c8704b756ab8fb10b08d6d"; };

  };

}
#endif
