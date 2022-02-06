#ifndef _ROS_SERVICE_OpenHRP_ObjectContactTurnaroundDetectorService_startObjectContactTurnaroundDetection_h
#define _ROS_SERVICE_OpenHRP_ObjectContactTurnaroundDetectorService_startObjectContactTurnaroundDetection_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_OBJECTCONTACTTURNAROUNDDETECTORSERVICE_STARTOBJECTCONTACTTURNAROUNDDETECTION[] = "hrpsys_ros_bridge/OpenHRP_ObjectContactTurnaroundDetectorService_startObjectContactTurnaroundDetection";

  class OpenHRP_ObjectContactTurnaroundDetectorService_startObjectContactTurnaroundDetectionRequest : public ros::Msg
  {
    public:
      typedef float _i_ref_diff_wrench_type;
      _i_ref_diff_wrench_type i_ref_diff_wrench;
      typedef float _i_max_time_type;
      _i_max_time_type i_max_time;
      uint32_t i_ee_names_length;
      typedef char* _i_ee_names_type;
      _i_ee_names_type st_i_ee_names;
      _i_ee_names_type * i_ee_names;

    OpenHRP_ObjectContactTurnaroundDetectorService_startObjectContactTurnaroundDetectionRequest():
      i_ref_diff_wrench(0),
      i_max_time(0),
      i_ee_names_length(0), i_ee_names(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->i_ref_diff_wrench);
      offset += serializeAvrFloat64(outbuffer + offset, this->i_max_time);
      *(outbuffer + offset + 0) = (this->i_ee_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->i_ee_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->i_ee_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->i_ee_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->i_ee_names_length);
      for( uint32_t i = 0; i < i_ee_names_length; i++){
      uint32_t length_i_ee_namesi = strlen(this->i_ee_names[i]);
      varToArr(outbuffer + offset, length_i_ee_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->i_ee_names[i], length_i_ee_namesi);
      offset += length_i_ee_namesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->i_ref_diff_wrench));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->i_max_time));
      uint32_t i_ee_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      i_ee_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      i_ee_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      i_ee_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->i_ee_names_length);
      if(i_ee_names_lengthT > i_ee_names_length)
        this->i_ee_names = (char**)realloc(this->i_ee_names, i_ee_names_lengthT * sizeof(char*));
      i_ee_names_length = i_ee_names_lengthT;
      for( uint32_t i = 0; i < i_ee_names_length; i++){
      uint32_t length_st_i_ee_names;
      arrToVar(length_st_i_ee_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_i_ee_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_i_ee_names-1]=0;
      this->st_i_ee_names = (char *)(inbuffer + offset-1);
      offset += length_st_i_ee_names;
        memcpy( &(this->i_ee_names[i]), &(this->st_i_ee_names), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return OPENHRP_OBJECTCONTACTTURNAROUNDDETECTORSERVICE_STARTOBJECTCONTACTTURNAROUNDDETECTION; };
    const char * getMD5(){ return "41330c5a4dc330b9b74e53118398a4db"; };

  };

  class OpenHRP_ObjectContactTurnaroundDetectorService_startObjectContactTurnaroundDetectionResponse : public ros::Msg
  {
    public:

    OpenHRP_ObjectContactTurnaroundDetectorService_startObjectContactTurnaroundDetectionResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return OPENHRP_OBJECTCONTACTTURNAROUNDDETECTORSERVICE_STARTOBJECTCONTACTTURNAROUNDDETECTION; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_ObjectContactTurnaroundDetectorService_startObjectContactTurnaroundDetection {
    public:
    typedef OpenHRP_ObjectContactTurnaroundDetectorService_startObjectContactTurnaroundDetectionRequest Request;
    typedef OpenHRP_ObjectContactTurnaroundDetectorService_startObjectContactTurnaroundDetectionResponse Response;
  };

}
#endif
