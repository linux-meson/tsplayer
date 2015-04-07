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

#include "AmCodec.hpp"

#include <cstring>

 class AmCodec::AmCodecPimpl {
 public:
	AmCodecPimpl();
public:
	codec_para_t pcodec;
 };

 AmCodec::AmCodecPimpl::AmCodecPimpl()
 {
	::memset((void*)&pcodec,0,sizeof(pcodec));
 }

AmCodec::AmCodec():mp_pimpl(new AmCodec::AmCodecPimpl())
{

}

AmCodec::~AmCodec() {
	// TODO Auto-generated destructor stub
}

int AmCodec::init()
{
	return ::codec_init(&(mp_pimpl->pcodec));
}

int AmCodec::close()
{
	return ::codec_close(&(mp_pimpl->pcodec));
}

int AmCodec::reset()
{
	int ret = CODEC_ERROR_NONE;
	ret = ::codec_reset(&(mp_pimpl->pcodec));
	return ret;
}

int AmCodec::pause()
{
	int ret = CODEC_ERROR_NONE;
	ret = ::codec_pause(&(mp_pimpl->pcodec));
	return ret;
}

int AmCodec::resume()
{
	int ret = CODEC_ERROR_NONE;
	ret = ::codec_resume(&(mp_pimpl->pcodec));
	return ret;
}

int AmCodec::write(void* buffer, int len)
{
	int ret = CODEC_ERROR_NONE;
	ret = ::codec_write(&(mp_pimpl->pcodec),buffer,len);
	return ret;
}

int AmCodec::checkin_pts(unsigned long pts)
{
	int ret = CODEC_ERROR_NONE;
	ret = ::codec_checkin_pts(&(mp_pimpl->pcodec),pts);
	return ret;
}

int AmCodec::get_vbuf_state(struct buf_status* buf)
{
	int ret = CODEC_ERROR_NONE;
	ret = ::codec_get_vbuf_state(&(mp_pimpl->pcodec), buf);
	return ret;
}

int AmCodec::get_vdec_state(struct vdec_status* vdec)
{
	int ret = CODEC_ERROR_NONE;
	ret = ::codec_get_vdec_state(&(mp_pimpl->pcodec), vdec);
	return ret;
}

int AmCodec::init_cntl()
{
	int ret = CODEC_ERROR_NONE;
	ret = ::codec_init_cntl(&(mp_pimpl->pcodec));
	return ret;
}

int AmCodec::poll_cntl()
{
	int ret = CODEC_ERROR_NONE;
	ret = ::codec_poll_cntl(&(mp_pimpl->pcodec));
	return ret;
}

int AmCodec::set_cntl_mode(unsigned int mode)
{
	int ret = CODEC_ERROR_NONE;
	ret = ::codec_set_cntl_mode(&(mp_pimpl->pcodec), mode);
	return ret;
}

int AmCodec::set_cntl_avthresh(unsigned int avthresh)
{
	int ret = CODEC_ERROR_NONE;
	ret = ::codec_set_cntl_avthresh(&(mp_pimpl->pcodec), avthresh);
	return ret;
}

int AmCodec::set_cntl_syncthresh(unsigned int syncthresh)
{
	int ret = CODEC_ERROR_NONE;
	ret = ::codec_set_cntl_syncthresh(&(mp_pimpl->pcodec),syncthresh);
	return ret;
}

int AmCodec::getAbufSize() const
{
	return mp_pimpl->pcodec.abuf_size;
}

void AmCodec::setAbufSize(int abufSize)
{
	mp_pimpl->pcodec.abuf_size = abufSize;
}

int AmCodec::getAudioChannels() const
{
	return mp_pimpl->pcodec.audio_channels;
}

void AmCodec::setAudioChannels(int audioChannels)
{
	mp_pimpl->pcodec.audio_channels = audioChannels;
}

int AmCodec::getAudioPid() const
{
	return mp_pimpl->pcodec.audio_pid;
}

void AmCodec::setAudioPid(int audioPid)
{
	mp_pimpl->pcodec.audio_pid = audioPid;
}

int AmCodec::getAudioSamplerate() const
{
	return mp_pimpl->pcodec.audio_samplerate;
}

void AmCodec::setAudioSamplerate(int audioSamplerate)
{
	mp_pimpl->pcodec.audio_samplerate = audioSamplerate;
}

int AmCodec::getAudioType() const
{
	return mp_pimpl->pcodec.audio_type;
}

void AmCodec::setAudioType(int audioType)
{
	mp_pimpl->pcodec.audio_type = audioType;
}

int AmCodec::getAvsyncThreshold() const
{
	return mp_pimpl->pcodec.avsync_threshold;
}

void AmCodec::setAvsyncThreshold(int avsyncThreshold)
{
	mp_pimpl->pcodec.avsync_threshold = avsyncThreshold;
}

bool AmCodec::isHasAudio() const
{
	return (mp_pimpl->pcodec.has_audio == 1 )?true:false;
}

void AmCodec::setHasAudio(bool hasAudio)
{
	mp_pimpl->pcodec.has_audio = (true == hasAudio)?1:0;
}

bool AmCodec::isHasSub() const
{
	return (mp_pimpl->pcodec.has_sub == 1)?true:false;
}

void AmCodec::setHasSub(bool hasSub)
{
	mp_pimpl->pcodec.has_sub = (true == hasSub)?1:0;
}

bool AmCodec::isHasVideo() const
{
	return (mp_pimpl->pcodec.has_video == 1)?true:false;
}

void AmCodec::setHasVideo(bool hasVideo)
{
	mp_pimpl->pcodec.has_video = (true == hasVideo)?1:0;
}

bool AmCodec::isNoblock() const
{
	return (mp_pimpl->pcodec.noblock == 1)?true:false;
}

void AmCodec::setNoblock(bool noblock)
{
	mp_pimpl->pcodec.noblock = (true == noblock)?1:0;
}

int AmCodec::getPacketSize() const
{
	return mp_pimpl->pcodec.packet_size;
}

void AmCodec::setPacketSize(int packetSize)
{
	mp_pimpl->pcodec.packet_size = packetSize;
}

int AmCodec::getSessionId() const
{
	return mp_pimpl->pcodec.SessionID;
}

void AmCodec::setSessionId(int sessionId)
{
	mp_pimpl->pcodec.SessionID = sessionId;
}

int AmCodec::getSubPid() const
{
	return mp_pimpl->pcodec.sub_pid;
}

void AmCodec::setSubPid(int subPid)
{
	mp_pimpl->pcodec.sub_pid = subPid;
}

int AmCodec::getSubType() const
{
	return mp_pimpl->pcodec.sub_type;
}

void AmCodec::setSubType(int subType)
{
	mp_pimpl->pcodec.sub_type = subType;
}

int AmCodec::getVbufSize() const
{
	return mp_pimpl->pcodec.vbuf_size;
}

void AmCodec::setVbufSize(int vbufSize)
{
	mp_pimpl->pcodec.vbuf_size = vbufSize;
}

int AmCodec::getVideoPid() const
{
	return mp_pimpl->pcodec.video_pid;
}

void AmCodec::setVideoPid(int videoPid)
{
	mp_pimpl->pcodec.video_pid = videoPid;
}

int AmCodec::getVideoType() const
{
	return mp_pimpl->pcodec.video_type;
}

void AmCodec::setVideoType(int videoType)
{
	mp_pimpl->pcodec.video_type = videoType;
}
