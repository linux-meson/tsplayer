/* @file
 *
 *  Copyright (C) 2015 Christian Ege <k4230r6@gmail.com>
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with TSPlayer; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#ifndef AMCODEC_HPP_
#define AMCODEC_HPP_

#include "IAmCodec.hpp"


typedef struct buf_status buf_status_t;
typedef struct vdec_status vdec_status_t;

class AmCodec: public IAmCodec {

public:
	AmCodec();
	virtual ~AmCodec();
	virtual int init();
	virtual int close();
	virtual int reset();
	virtual int pause();
	virtual int resume();
	virtual int write(void* buffer, int len);
	virtual int checkin_pts(unsigned long pts);
	virtual int get_vbuf_state(buf_status_t* buf);
	virtual int get_vdec_state(vdec_status_t* vdec);

	virtual int init_cntl();
	virtual int poll_cntl();
	virtual int set_cntl_mode(unsigned int mode);
	virtual int set_cntl_avthresh(unsigned int avthresh);
	virtual int set_cntl_syncthresh(unsigned int syncthresh);

	virtual int getAbufSize() const;
	virtual void setAbufSize(int abufSize);
	virtual int getAudioChannels() const;
	virtual void setAudioChannels(int audioChannels);
	virtual int getAudioPid() const;
	virtual void setAudioPid(int audioPid);
	virtual int getAudioSamplerate() const;
	virtual void setAudioSamplerate(int audioSamplerate);
	virtual int getAudioType() const;
	virtual void setAudioType(int audioType);
	virtual int getAvsyncThreshold() const;
	virtual void setAvsyncThreshold(int avsyncThreshold);
	virtual bool isHasAudio() const;
	virtual void setHasAudio(bool hasAudio);
	virtual bool isHasSub() const;
	virtual void setHasSub(bool hasSub);
	virtual bool isHasVideo() const;
	virtual void setHasVideo(bool hasVideo);
	virtual bool isNoblock() const;
	virtual void setNoblock(bool noblock);
	virtual int getPacketSize() const;
	virtual void setPacketSize(int packetSize);
	virtual int getSessionId() const;
	virtual void setSessionId(int sessionId);
	virtual int getSubPid() const;
	virtual void setSubPid(int subPid);
	virtual int getSubType() const;
	virtual void setSubType(int subType);
	virtual int getVbufSize() const;
	virtual void setVbufSize(int vbufSize);
	virtual int getVideoPid() const;
	virtual void setVideoPid(int videoPid);
	virtual int getVideoType() const;
	virtual void setVideoType(int videoType);


private:
	class AmCodecPimpl;
	AmCodecPimpl* mp_pimpl;
};

#endif /* AMCODEC_HPP_ */
