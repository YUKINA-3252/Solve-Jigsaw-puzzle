#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_ObjectContactTurnaroundDetectorService_objectContactTurnaroundDetectorParam_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_ObjectContactTurnaroundDetectorService_objectContactTurnaroundDetectorParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_ObjectContactTurnaroundDetectorService_objectContactTurnaroundDetectorParam : public ros::Msg
  {
    public:
      typedef float _wrench_cutoff_freq_type;
      _wrench_cutoff_freq_type wrench_cutoff_freq;
      typedef float _dwrench_cutoff_freq_type;
      _dwrench_cutoff_freq_type dwrench_cutoff_freq;
      typedef float _detect_ratio_thre_type;
      _detect_ratio_thre_type detect_ratio_thre;
      typedef float _start_ratio_thre_type;
      _start_ratio_thre_type start_ratio_thre;
      typedef float _detect_time_thre_type;
      _detect_time_thre_type detect_time_thre;
      typedef float _start_time_thre_type;
      _start_time_thre_type start_time_thre;
      float axis[3];
      float moment_center[3];
      typedef int64_t _detector_total_wrench_type;
      _detector_total_wrench_type detector_total_wrench;

    OpenHRP_ObjectContactTurnaroundDetectorService_objectContactTurnaroundDetectorParam():
      wrench_cutoff_freq(0),
      dwrench_cutoff_freq(0),
      detect_ratio_thre(0),
      start_ratio_thre(0),
      detect_time_thre(0),
      start_time_thre(0),
      axis(),
      moment_center(),
      detector_total_wrench(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->wrench_cutoff_freq);
      offset += serializeAvrFloat64(outbuffer + offset, this->dwrench_cutoff_freq);
      offset += serializeAvrFloat64(outbuffer + offset, this->detect_ratio_thre);
      offset += serializeAvrFloat64(outbuffer + offset, this->start_ratio_thre);
      offset += serializeAvrFloat64(outbuffer + offset, this->detect_time_thre);
      offset += serializeAvrFloat64(outbuffer + offset, this->start_time_thre);
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->axis[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->moment_center[i]);
      }
      union {
        int64_t real;
        uint64_t base;
      } u_detector_total_wrench;
      u_detector_total_wrench.real = this->detector_total_wrench;
      *(outbuffer + offset + 0) = (u_detector_total_wrench.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_detector_total_wrench.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_detector_total_wrench.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_detector_total_wrench.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_detector_total_wrench.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_detector_total_wrench.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_detector_total_wrench.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_detector_total_wrench.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->detector_total_wrench);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->wrench_cutoff_freq));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->dwrench_cutoff_freq));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->detect_ratio_thre));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->start_ratio_thre));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->detect_time_thre));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->start_time_thre));
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->axis[i]));
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->moment_center[i]));
      }
      union {
        int64_t real;
        uint64_t base;
      } u_detector_total_wrench;
      u_detector_total_wrench.base = 0;
      u_detector_total_wrench.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_detector_total_wrench.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_detector_total_wrench.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_detector_total_wrench.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_detector_total_wrench.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_detector_total_wrench.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_detector_total_wrench.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_detector_total_wrench.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->detector_total_wrench = u_detector_total_wrench.real;
      offset += sizeof(this->detector_total_wrench);
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_ObjectContactTurnaroundDetectorService_objectContactTurnaroundDetectorParam"; };
    const char * getMD5(){ return "d15910ebf1dd211b9d41019db8254528"; };

  };

}
#endif
