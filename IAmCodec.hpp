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

extern "C" {
#include <amcodec/codec.h>
#include <amcodec/codec_error.h>
}

#ifndef IAMCODEC_HPP__
#define IAMCODEC_HPP__

class IAmCodec
{

public:
	virtual ~IAmCodec();

	virtual int init()=0;
	virtual int close()=0;
	virtual int reset()=0;
	virtual int pause()=0;
	virtual int resume()=0;
	virtual int write(void *buffer, int len)=0;
	virtual int checkin_pts(unsigned long pts)=0;
	virtual int get_vbuf_state(struct buf_status *buf)=0;
	virtual int get_vdec_state(struct vdec_status *vdec)=0;

	virtual int init_cntl()=0;
	virtual int poll_cntl()=0;
	virtual int set_cntl_mode(unsigned int mode)=0;
	virtual int set_cntl_avthresh(unsigned int avthresh)=0;
	virtual int set_cntl_syncthresh(unsigned int syncthresh)=0;

	virtual int getAbufSize() const = 0;
	virtual void setAbufSize(int abufSize) = 0;
	virtual int getAudioChannels() const = 0;
	virtual void setAudioChannels(int audioChannels) = 0;
	virtual int getAudioPid() const = 0;
	virtual void setAudioPid(int audioPid) = 0;
	virtual int getAudioSamplerate() const = 0;
	virtual void setAudioSamplerate(int audioSamplerate) = 0;
	virtual int getAudioType() const = 0;
	virtual void setAudioType(int audioType) = 0;
	virtual int getAvsyncThreshold() const = 0;
	virtual void setAvsyncThreshold(int avsyncThreshold) = 0;
	virtual bool isHasAudio() const = 0;
	virtual void setHasAudio(bool hasAudio) = 0;
	virtual bool isHasSub() const = 0;
	virtual void setHasSub(bool hasSub) = 0;
	virtual bool isHasVideo() const = 0;
	virtual void setHasVideo(bool hasVideo) = 0;
	virtual bool isNoblock() const = 0;
	virtual void setNoblock(bool noblock) = 0;
	virtual int getPacketSize() const = 0;
	virtual void setPacketSize(int packetSize) = 0;
	virtual int getSessionId() const = 0;
	virtual void setSessionId(int sessionId) = 0;
	virtual int getSubPid() const = 0;
	virtual void setSubPid(int subPid) = 0;
	virtual int getSubType() const = 0;
	virtual void setSubType(int subType) = 0;
	virtual int getVbufSize() const = 0;
	virtual void setVbufSize(int vbufSize) = 0;
	virtual int getVideoPid() const = 0;
	virtual void setVideoPid(int videoPid) = 0;
	virtual int getVideoType() const = 0;
	virtual void setVideoType(int videoType) = 0;

protected:
	IAmCodec();



};

#endif
