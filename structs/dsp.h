#include "shared.h"

// maybe virtual device?
struct HardwareDevice {
    /* 0x0000 */ AudioRenderSession* renderSession;
    /* 0x0004 */ s32 state; // 0 = invalid, 1 = running, 2 = paused, 3 = ?
    /* 0x0008 */ void* ringBufferBase;
    /* 0x000C */ s32 ringBufferSize;
    /* 0x0010 */ s32 hardwareReadPosition;
    /* 0x0014 */ s32 ringBufferPos;
    /* 0x0018 */ s32 hardwareQueuedBytes;
    /* 0x001C */ s32 channelCount;
    /* 0x0020 */ s16 sampleBuffer[0x800]; // 240 samples per 6 channels, 240 * 6 * sizeof(s16) = 0xB40
                                          // is that right? seems like it's a clean 0x1000 bytes regardless
}; // size = 0x1020

struct MixDevice {
    /* 0x000 */ HardwareDevice* hardwareDevice;
    /* 0x004 */ char name[0x100];
    /* 0x104 */ s32 sessionId;
}; // size = 0x108

struct SessionBase {
    /* 0x00 */ struct SessionBase::vtable* __vftable;
    /* 0x04 */ char unk04[0xC];
}; // size = 0x10

struct SessionBase::vtable {
    /* 0x00 */ s32 (*unk_00)(SessionBase*);
    /* 0x04 */ s32 (*unk_04)(SessionBase*);
    /* 0x08 */ s32 (*unk_08)(SessionBase*);
    /* 0x0C */ s32 (*unk_0C)(SessionBase*);
    /* 0x10 */ s32 (*unk_10)(SessionBase*);
    /* 0x14 */ s32 (*unk_14)(SessionBase*);
    /* 0x18 */ void (*SetSamplesProcessed)(SessionBase*);
    /* 0x1C */ s32 (*GetSharedBufferPosition)(SessionBase*);
    /* 0x20 */ void (*SetSharedBufferPosition)(SessionBase*);
    /* 0x24 */ void (*virt24)(SessionBase*);
    /* 0x28 */ void (*AppendBuffer)(SessionBase*);
    /* 0x2C */ void (*GetBuffersProcessed)(SessionBase*);
    /* 0x30 */ void (*virt30)(SessionBase*);
    /* 0x34 */ void (*virt34)(SessionBase*);
    /* 0x38 */ void (*virt38)(SessionBase*);
    /* 0x3C */ void (*unk_3C)(SessionBase*);
    /* 0x40 */ void (*Resume)(SessionBase*);
    /* 0x44 */ void (*unk_44)(SessionBase*);
    /* 0x48 */ void (*unk_48)(SessionBase*);
    /* 0x4C */ s32 (*unk_4C)(SessionBase*);
    /* 0x50 */ s32 (*AttachWorkBuffer)(SessionBase*);
    /* 0x54 */ s32 (*Open)(SessionBase*);
    /* 0x58 */ s32 (*Close)(SessionBase*);
    /* 0x5C */ bool (*unk_5C)(SessionBase*);
    /* 0x60 */ bool (*PrepareSamples)(SessionBase*);
    /* 0x64 */ bool (*virt64)(SessionBase*);
    /* 0x68 */ bool (*unk_68)(SessionBase*);
    /* 0x6C */ bool (*virt6C)(SessionBase*);
};

// same as SessionThing in audio.h?
struct UnkSessionStruct {
    /* 0x00 */ struct UnkSessionStruct::vtable* __vftable;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
}; // size = 0x1C

struct UnkSessionStruct::vtable {
    /* 0x00 */ void (*D2)(void);
    /* 0x04 */ void (*D0)(void);
};

struct AudioRenderSession::vftable1 {
    /* 0x00 */ s16* (*GetRingBuffer)(AudioRenderSession*);
    /* 0x04 */ s32 (*GetBufferDeviceAddress)(AudioRenderSession*);
    /* 0x08 */ s32 (*GetRingBufferSize)(AudioRenderSession*);
    /* 0x0C */ s32 (*GetReadPosition)(AudioRenderSession*);
    /* 0x10 */ s32 (*GetWritePosition)(AudioRenderSession*);
    /* 0x14 */ s32 (*Unk14)(AudioRenderSession*);
    /* 0x18 */ void (*SetSamplesProcessed)(AudioRenderSession*);
    /* 0x1C */ s32 (*GetSharedBufferPosition)(AudioRenderSession*);
    /* 0x20 */ void (*SetSharedBufferPosition)(AudioRenderSession*);
    /* 0x24 */ void (*SetWritePosition)(AudioRenderSession*);
    /* 0x28 */ void (*AppendBuffer)(AudioRenderSession*);
    /* 0x2C */ void (*GetBuffersProcessed)(AudioRenderSession*);
    /* 0x30 */ void (*Unk30)(AudioRenderSession*);
    /* 0x34 */ void (*Unk34)(AudioRenderSession*);
    /* 0x38 */ void (*FlushBuffers)(AudioRenderSession*);
    /* 0x3C */ void (*Suspend)(AudioRenderSession*);
    /* 0x40 */ void (*Resume)(AudioRenderSession*);
    /* 0x44 */ void (*Unk44)(AudioRenderSession*);
    /* 0x48 */ void (*Unk48)(AudioRenderSession*);
    /* 0x4C */ s32 (*Unk4C)(AudioRenderSession*);
    /* 0x50 */ s32 (*AttachWorkBuffer)(AudioRenderSession*);
    /* 0x54 */ s32 (*Open)(AudioRenderSession*, s32, s32, s32, s32, s32, s32, s32);
    /* 0x58 */ s32 (*Close)(AudioRenderSession*);
    /* 0x5C */ bool (*Unk5C)(AudioRenderSession*);
    /* 0x60 */ void (*PrepareSamples)(AudioRenderSession*);
    /* 0x64 */ void (*Unk64)(AudioRenderSession*);
    /* 0x68 */ void (*GetSampleCount)(AudioRenderSession*);
    /* 0x6C */ void (*SetReadPosition)(AudioRenderSession*);
};

struct AudioRenderSession {
    /* 0x00 */ AudioRenderSession::vftable1* __vftable1; // Session__vtable1
    /* 0x04 */ s32 refCount;
    /* 0x08 */ s32 unk_08; // maps a given buffer in AppendBuffer if set to 0
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 channelCount;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ AudioRenderSession::vftable1* __vftable2; // SessionBase__vftable
    /* 0x24 */ u32 ringBufferBase;
    /* 0x28 */ u32 dataOffset2;
    /* 0x2C */ s32 totalBuffersByteSize; // init'd to 0x6000, total buffer size? 
    /* 0x30 */ s32 bufferSize; // init'd to 0x2000
    /* 0x34 */ s32 unk_34; // init'd to 0x800, max sample count?
    /* 0x38 */ s32 readPosition; // init'd to unknown things
    /* 0x3C */ s32 writePosition; // init'd to unknown things
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ s32 unk_48;
    /* 0x4C */ s32 suspended;
    /* 0x50 */ char unk50[0x4];
    /* 0x54 */ UnkSessionStruct unk_54; // UnkSession_vtable
    /* 0x70 */ UnkSessionStruct unk_70; // UnkSession_vtable
    /* 0x8C */ MixRender* mixRender; // points to its place in gMixData
}; // size = 0x90

struct SessionStruct {
    /* 0x00 */ char unk00[0x4];
    /* 0x04 */ u32 addr1;
    /* 0x08 */ u32 addr2;
    /* 0x0C */ s32 size;
}; // size = 0x10

struct AudioOutSession {
    /* 0x00 */ AudioRenderSession::vftable1* __vftable1; // Session__vtable1
    /* 0x04 */ s32 refCount;
    /* 0x08 */ s32 unk_08; // buffer unmapped if set to 0
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 channelCount;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ AudioRenderSession::vftable1* __vftable2; // SessionBase__vftable
    /* 0x24 */ u32 dataOffset;
    /* 0x28 */ u32 dataOffset2;
    /* 0x2C */ s32 totalBuffersByteSize; // init'd to 0x6000, total buffer size? 
    /* 0x30 */ s32 bufferSize; // init'd to 0x2000
    /* 0x34 */ s32 sampleCount; // init'd to 0x800, changed to bufferSize / 2 / channelcount, 0x2000 / 2 / 2 = 0x800
    /* 0x38 */ s32 readPosition; // init'd to unknown things
    /* 0x3C */ s32 writePosition; // init'd to unknown things
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ s32 unk_48;
    /* 0x4C */ s32 suspended;
    /* 0x50 */ bool flushBuffers; // set to 1 in FlushBuffers
    /* 0x54 */ UnkSessionStruct unk_54; // UnkSession_vtable
    /* 0x70 */ UnkSessionStruct unk_70; // UnkSession_vtable
    /* 0x8C */ MixOut* mixOut; // points to its place in gMixData
    /* 0x90 */ SessionStruct subStruct[4];
    /* 0xD0 */ s32 subStructCount; // max/registered count, below being currentIndex?
    /* 0xD4 */ s32 unk_D4; // if this equals subStructCount, change session info to match
}; // size = 0xD8

struct NearVoiceGameRecordUnkStruct {
    /* 0x00 */ u32 audioBuffer0;
    /* 0x04 */ u32 audioBuffer1;
    /* 0x08 */ u32 audioBuffer1_2;
    /* 0x0C */ u32 readPosition; // an index into the buffer, not address
    /* 0x10 */ u32 dataSizeBytes;
    /* 0x14 */ u32 frameCount; // dataSize / (2 * channelCount)
    /* 0x18 */ u32 dataSizeBytes2;
    /* 0x1C */ u32 readAddress;
    /* 0x20 */ u32 bufferOffset; // writePosition
    /* 0x24 */ u32 remainingBufferSize; // sizeBytesTotal - readPosition
    /* 0x28 */ u32 numFramesRemaining; // sizeRemaining / frameSize
    /* 0x2C */ u32 sizeBytesTotal;
    /* 0x30 */ u32 frameSize;
    /* 0x34 */ bool isNew; // set to 1 in AttachWorkbuffer, if 0, invalidate audioBuffer1_2 + readPosition with remainingSize
    /* 0x35 */ bool unk_35; // set to 1 in AttachWorkbuffer
    /* 0x36 */ char pad[0x2];
}; // size >= 0x38

struct NearVoiceSession {
    /* 0x00 */ AudioRenderSession::vftable1* __vftable1; // Session__vtable1
    /* 0x04 */ s32 refCount;
    /* 0x08 */ s32 unk_08; // buffer unmapped if set to 0
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 channelCount;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ AudioRenderSession::vftable1* __vftable2; // SessionBase__vftable
    /* 0x24 */ u32 dataOffset;
    /* 0x28 */ u32 dataOffset2;
    /* 0x2C */ s32 totalBuffersByteSize; // init'd to 0x6000, total buffer size? 
    /* 0x30 */ s32 bufferSize; // init'd to 0x2000
    /* 0x34 */ s32 sampleCount; // init'd to 0x800, changed to bufferSize / 2 / channelcount, 0x2000 / 2 / 2 = 0x800
    /* 0x38 */ s32 readPosition; // init'd to unknown things
    /* 0x3C */ s32 writePosition; // init'd to unknown things
    /* 0x40 */ s32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ s32 unk_48;
    /* 0x4C */ s32 suspended;
    /* 0x50 */ bool flushBuffers; // set to 1 in FlushBuffers
    /* 0x54 */ UnkSessionStruct unk_54; // UnkSession_vtable
    /* 0x70 */ UnkSessionStruct unk_70; // UnkSession_vtable
    /* 0x8C */ MixNearVoice* mixNearVoice; // points to its place in gMixData
    /* 0x90 */ NearVoiceGameRecordUnkStruct unk_90;
    /* 0xC8 */ char unkC8[0x48];
}; // size = 0x110

struct GameRecordSession {
    /* 0x000 */ char unk000[0x110];
}; // size = 0x110

struct SessionRegistry {
    /* 0x00000 */ char unk00000[0x4];
    /* 0x00004 */ bool stopFlag;
    /* 0x00005 */ char unk00005[0x3];
    /* 0x00008 */ char unk00008[0xB8]; // unk2ED00 in gMixData
    /* 0x000C0 */ char unk000C0[6][0x6000]; // [0] default, [1] sessionType 8
    /* 0x240C0 */ s32 unk_240C0;
    /* 0x240C0 */ s32 unk_240C4;
    /* 0x240C8 */ timer_t timr_240C8;
    /* 0x240F0 */ char unk240F0[0xC];
    /* 0x240FC */ semaphore_t sink_semaphore; // signaleld for gMix MainLoop sink samples?
    /* 0x24124 */ semaphore_t* sessionSemaphores[3];
    /* 0x24130 */ char unk24130[0x4];
    /* 0x24134 */ s32 gMixMsgSize; // this is what's sent from firmware
    /* 0x24138 */ s32 gMixMsgData[8];
    /* 0x24158 */ semaphore_t process_semaphore; // signalled for gMix MainLoop ProcessMessage
    /* 0x24180 */ char unk24180[0x8];
    /* 0x24188 */ gMixData* mixData;
    /* 0x2418C */ char unk2418C[0x18];
    /* 0x241A4 */ adsp_mbx_t mailbox;
    /* 0x24224 */ char unk24224[0x4];
    /* 0x24228 */ UnkSessionStruct unk_24228;
    /* 0x24244 */ UnkSessionStruct unk_24244;
    /* 0x24260 */ AudioRenderSession renderSessions[6];
    /* 0x245C0 */ AudioOutSession audioOutSessions[12];
    /* 0x24FE0 */ char unk24FE0[0x438];
    /* 0x25418 */ NearVoiceSession nearVoiceSessions[2];
    /* 0x25638 */ GameRecordSession gameRecordSession[4];
    /* 0x25A78 */ char sessionType7[2][0x90];
    /* 0x25B98 */ char sessionType8[0x90];
    /* 0x25C28 */ s32 unk_sessionType;
    /* 0x25C2C */ s32 unk_25C2C;
}; // size = 0x25C30
