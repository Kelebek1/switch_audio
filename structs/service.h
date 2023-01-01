typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long s64;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef float f32;
typedef double f64;


// =================== SERVICE BASES ===================
// service objects have these as bases, usually coming after the object itself

#include "nn/nn.h"

// nn::Result ServiceHandler_IAudioOutManager(nn::sf::IServiceObject *object, nn::sf::cmif::server::CmifServerMessage *message, nn::sf::detail::PointerAndSize const *pas)
// nn::Result Process_IAudioOutManager_ListAudioOuts(nn::sf::cmif::CmifOutHeader **, Interface *, nn::sf::cmif::server::CmifServerMessage *, nn::sf::detail::PointerAndSize *)

// =================== SERVICE ===================

struct nn::audio::detail::IAudioRendererManager {
    struct nn::audio::server::IAudioRendererManagerImpl::vtbl* __vftable;
};

struct nn::audio::server::IAudioRendererManagerImpl::vtbl {
    /* 0x00 */ void (*AddReference)(nn::audio::detail::IAudioRendererManager*);
    /* 0x08 */ void (*Release)(nn::audio::detail::IAudioRendererManager*);
    /* 0x10 */ void (*GetProxyInfo)(nn::audio::detail::IAudioRendererManager*);
    /* 0x18 */ void (*GetInterfaceTypeInfo)(nn::audio::detail::IAudioRendererManager*);

    /* 0x20 */ void (*OpenAudioRenderer)(nn::audio::detail::IAudioRendererManager*);
    /* 0x28 */ void (*GetWorkBufferSize)(nn::audio::detail::IAudioRendererManager*);
    /* 0x30 */ void (*GetAudioDeviceService)(nn::audio::detail::IAudioRendererManager*);
    /* 0x38 */ void (*OpenAudioRendererForManualExecution)(nn::audio::detail::IAudioRendererManager*);
    /* 0x40 */ void (*GetAudioDeviceServiceWithRevisionInfo)(nn::audio::detail::IAudioRendererManager*);
}; // size = 0x20

struct nn::audio::server::IAudioRenderer {
    struct nn::audio::server::IAudioRenderer::vtbl* __vftable;
};

struct nn::audio::server::IAudioRenderer::vtbl {
    /* 0x00 */ void (*AddReference)(nn::audio::server::IAudioRenderer*);
    /* 0x08 */ void (*Release)(nn::audio::server::IAudioRenderer*);
    /* 0x10 */ void (*GetProxyInfo)(nn::audio::server::IAudioRenderer*);
    /* 0x18 */ void (*GetInterfaceTypeInfo)(nn::audio::server::IAudioRenderer*);

    /* 0x20 */ void (*GetSampleRate)(nn::audio::server::IAudioRenderer*);
    /* 0x28 */ void (*GetSampleCount)(nn::audio::server::IAudioRenderer*);
    /* 0x30 */ void (*GetMixBuffer)(nn::audio::server::IAudioRenderer*);
    /* 0x40 */ void (*GetState)(nn::audio::server::IAudioRenderer*);
    /* 0x48 */ void (*RequestUpdate)(nn::audio::server::IAudioRenderer*);
    /* 0x50 */ void (*Start)(nn::audio::server::IAudioRenderer*);
    /* 0x58 */ void (*Stop)(nn::audio::server::IAudioRenderer*);
    /* 0x60 */ void (*QuerySystemEvent)(nn::audio::server::IAudioRenderer*);
    /* 0x68 */ void (*SetRenderingTimeLimit)(nn::audio::server::IAudioRenderer*);
    /* 0x70 */ void (*GetRenderingTimeLimit)(nn::audio::server::IAudioRenderer*);
    /* 0x78 */ void (*RequestUpdateAuto)(nn::audio::server::IAudioRenderer*);
    /* 0x80 */ void (*ExecuteAudioRendererRendering)(nn::audio::server::IAudioRenderer*);
}; // size = 0x88

// audout:u
struct nn::audio::server::IAudioOutManager {
    /* 0x00 */ struct nn::audio::server::IAudioOutManager::vtbl* __vtable;
    /* 0x08 */ nn::sf::hipc::client::Hipc2ClientProxyBaseObject proxyBase;
    /* 0x10 */ nn::sf::detail::CmifProxyInfo proxyInfo;
}; // size = 0x20

struct nn::audio::server::IAudioOutManager::vtbl {
    /* 0x00 */ void (*AddReference)(nn::audio::server::IAudioOutManager*);
    /* 0x08 */ void (*Release)(nn::audio::server::IAudioOutManager*);
    /* 0x10 */ void (*GetProxyInfo)(nn::audio::server::IAudioOutManager*);
    /* 0x18 */ void (*GetInterfaceTypeInfo)(nn::audio::server::IAudioOutManager*);

    /* 0x20 */ nn::Result (*ListAudioOuts)(nn::audio::server::IAudioOutManager*, nn::sf::detail::PointerAndSize** outNames, s32* outCount);
    /* 0x28 */ nn::Result (*OpenAudioOut)(nn::audio::server::IAudioOutManager*);
    /* 0x30 */ nn::Result (*ListAudioOutsAuto)(nn::audio::server::IAudioOutManager*);
    /* 0x38 */ nn::Result (*OpenAudioOutAuto)(nn::audio::server::IAudioOutManager*);
};

struct nn::audio::server::IAudioOut::vtbl {
    /* 0x00 */ void (*AddReference)(struct nn::audio::server::IAudioOut*);
    /* 0x08 */ void (*Release)(struct nn::audio::server::IAudioOut*);
    /* 0x10 */ void (*GetProxyInfo)(struct nn::audio::server::IAudioOut*);
    /* 0x18 */ void (*GetInterfaceTypeInfo)(struct nn::audio::server::IAudioOut*);

    /* 0x20 */ nn::Result (*GetAudioOutState)(struct nn::audio::server::IAudioOut*);
    /* 0x28 */ nn::Result (*Start)(struct nn::audio::server::IAudioOut*);
    /* 0x30 */ nn::Result (*Stop)(struct nn::audio::server::IAudioOut*);
    /* 0x38 */ nn::Result (*AppendAudioOutBuffer)(struct nn::audio::server::IAudioOut*);
    /* 0x40 */ nn::Result (*RegisterBufferEvent)(struct nn::audio::server::IAudioOut*);
    /* 0x48 */ nn::Result (*GetReleasedAudioOutBuffers)(struct nn::audio::server::IAudioOut*);
    /* 0x50 */ nn::Result (*ContainsAudioOutBuffer)(struct nn::audio::server::IAudioOut*);
    /* 0x58 */ nn::Result (*AppendAudioOutBufferAuto)(struct nn::audio::server::IAudioOut*);
    /* 0x60 */ nn::Result (*GetReleasedAudioOutBuffersAuto)(struct nn::audio::server::IAudioOut*);
    /* 0x68 */ nn::Result (*GetAudioOutBufferCount)(struct nn::audio::server::IAudioOut*);
    /* 0x70 */ nn::Result (*GetAudioOutPlayedSampleCount)(struct nn::audio::server::IAudioOut*);
    /* 0x78 */ nn::Result (*FlushAudioOutBuffers)(struct nn::audio::server::IAudioOut*);
    /* 0x80 */ nn::Result (*SetAudioOutVolume)(struct nn::audio::server::IAudioOut*);
    /* 0x88 */ nn::Result (*GetAudioOutVolume)(struct nn::audio::server::IAudioOut*);
};

struct nn::audio::IAudioInManager {
    /* 0x000 */ struct nn::audio::server::IAudioInManager::vtbl* __vftable;
};

struct nn::audio::server::IAudioInManager::vtbl {
    /* 0x00 */ void (*AddReference)(nn::audio::IAudioInManager*);
    /* 0x08 */ void (*Release)(nn::audio::IAudioInManager*);
    /* 0x10 */ void (*GetProxyInfo)(nn::audio::IAudioInManager*);
    /* 0x18 */ void (*GetInterfaceTypeInfo)(nn::audio::IAudioInManager*);

    /* 0x20 */ nn::Result (*ListAudioIns)(nn::audio::IAudioInManager*, nn::sf::detail::PointerAndSize** outNames, s32* outCount);
    /* 0x28 */ nn::Result (*OpenAudioIn)(nn::audio::IAudioInManager*);
    /* 0x30 */ nn::Result (*ListAudioInsAuto)(nn::audio::IAudioInManager*);
    /* 0x38 */ nn::Result (*OpenAudioInAuto)(nn::audio::IAudioInManager*);
    /* 0x38 */ nn::Result (*ListAudioInsAutoFiltered)(nn::audio::IAudioInManager*);
    /* 0x38 */ nn::Result (*OpenAudioInProtocolSpecified)(nn::audio::IAudioInManager*);
};

struct nn::audio::IAudioIn::vtbl {
    /* 0x00 */ void (*AddReference)(struct nn::audio::AudioIn*);
    /* 0x08 */ void (*Release)(struct nn::audio::AudioIn*);
    /* 0x10 */ void (*GetProxyInfo)(struct nn::audio::AudioIn*);
    /* 0x18 */ void (*GetInterfaceTypeInfo)(struct nn::audio::AudioIn*);

    /* 0x20 */ nn::Result (*GetAudioInState)(struct nn::audio::AudioIn*);
    /* 0x28 */ nn::Result (*Start)(struct nn::audio::AudioIn*);
    /* 0x30 */ nn::Result (*Stop)(struct nn::audio::AudioIn*);
    /* 0x38 */ nn::Result (*AppendAudioInBuffer)(struct nn::audio::AudioIn*);
    /* 0x40 */ nn::Result (*RegisterBufferEvent)(struct nn::audio::AudioIn*);
    /* 0x48 */ nn::Result (*GetReleasedAudioInBuffers)(struct nn::audio::AudioIn*);
    /* 0x50 */ nn::Result (*ContainsAudioInBuffer)(struct nn::audio::AudioIn*);
    /* 0x58 */ nn::Result (*AppendUacInBuffer)(struct nn::audio::AudioIn*);
    /* 0x60 */ nn::Result (*AppendAudioInBufferAuto)(struct nn::audio::AudioIn*);
    /* 0x68 */ nn::Result (*GetReleasedAudioInBuffersAuto)(struct nn::audio::AudioIn*);
    /* 0x70 */ nn::Result (*AppendUacInBufferAuto)(struct nn::audio::AudioIn*);
    /* 0x78 */ nn::Result (*GetAudioInBufferCount)(struct nn::audio::AudioIn*);
    /* 0x80 */ nn::Result (*SetDeviceGain)(struct nn::audio::AudioIn*);
    /* 0x88 */ nn::Result (*GetDeviceGain)(struct nn::audio::AudioIn*);
    /* 0x90 */ nn::Result (*FlushAudioInBuffers)(struct nn::audio::AudioIn*);
};

struct nn::audio::IFinalOutputRecorderManager {
    /* 0x000 */ struct nn::audio::IFinalOutputRecorderManager::vtable* __vftable;
};

struct nn::audio::IFinalOutputRecorderManager::vtable {
    /* 0x00 */ void (*AddReference)(struct nn::audio::IFinalOutputRecorderManager*);
    /* 0x08 */ void (*Release)(struct nn::audio::IFinalOutputRecorderManager*);
    /* 0x10 */ void (*GetProxyInfo)(struct nn::audio::IFinalOutputRecorderManager*);
    /* 0x18 */ void (*GetInterfaceTypeInfo)(struct nn::audio::IFinalOutputRecorderManager*);

    /* 0x00 */ void (*OpenFinalOutputRecorder)(nn::audio::IFinalOutputRecorderManager*);
    /* 0x08 */ void (*D2)(nn::audio::IFinalOutputRecorderManager*);
    /* 0x10 */ void (*D0)(nn::audio::IFinalOutputRecorderManager*);
}; 

struct nn::audio::FinalOutputRecorder::vtable {
    /* 0x00 */ void (*AddReference)(struct nn::audio::FinalOutputRecorder*);
    /* 0x08 */ void (*Release)(struct nn::audio::FinalOutputRecorder*);
    /* 0x10 */ void (*GetProxyInfo)(struct nn::audio::FinalOutputRecorder*);
    /* 0x18 */ void (*GetInterfaceTypeInfo)(struct nn::audio::FinalOutputRecorder*);

    /* 0x20 */ nn::Result (*GetFinalOutputRecorderState)(struct nn::audio::FinalOutputRecorder*);
    /* 0x28 */ nn::Result (*Start)(struct nn::audio::FinalOutputRecorder*);
    /* 0x30 */ nn::Result (*Stop)(struct nn::audio::FinalOutputRecorder*);
    /* 0x38 */ nn::Result (*AppendFinalOutputRecorderBuffer)(struct nn::audio::FinalOutputRecorder*);
    /* 0x40 */ nn::Result (*RegisterBufferEvent)(struct nn::audio::FinalOutputRecorder*);
    /* 0x48 */ nn::Result (*GetReleasedFinalOutputRecorderBuffers)(struct nn::audio::FinalOutputRecorder*);
    /* 0x50 */ nn::Result (*ContainsFinalOutputRecorderBuffer)(struct nn::audio::FinalOutputRecorder*);
    /* 0x58 */ nn::Result (*AppendFinalOutputRecorderBufferEndTime)(struct nn::audio::FinalOutputRecorder*);
    /* 0x60 */ nn::Result (*AppendFinalOutputRecorderBufferAuto)(struct nn::audio::FinalOutputRecorder*);
    /* 0x68 */ nn::Result (*GetReleasedFinalOutputRecorderBuffersAuto)(struct nn::audio::FinalOutputRecorder*);
    /* 0x70 */ nn::Result (*FlushFinalOutputRecorderBuffers)(struct nn::audio::FinalOutputRecorder*);
    /* 0x78 */ nn::Result (*AttachWorkbuffer)(struct nn::audio::FinalOutputRecorder*);
};

struct nn::audio::server::IAudioDevice::vtbl {
    /* 0x00 */ void (*AddReference)(struct nn::audio::server::IAudioDevice*);
    /* 0x08 */ void (*Release)(struct nn::audio::server::IAudioDevice*);
    /* 0x10 */ void (*GetProxyInfo)(struct nn::audio::server::IAudioDevice*);
    /* 0x18 */ void (*GetInterfaceTypeInfo)(struct nn::audio::server::IAudioDevice*);

    /* 0x20 */ nn::Result (*ListAudioDeviceName)(struct nn::audio::server::IAudioDevice*);
    /* 0x28 */ nn::Result (*SetAudioDeviceOutputVolume)(struct nn::audio::server::IAudioDevice*);
    /* 0x30 */ nn::Result (*GetAudioDeviceOutputVolume)(struct nn::audio::server::IAudioDevice*);
    /* 0x38 */ nn::Result (*GetActiveAudioDeviceName)(struct nn::audio::server::IAudioDevice*);
    /* 0x40 */ nn::Result (*QueryAudioDeviceSystemEvent)(struct nn::audio::server::IAudioDevice*);
    /* 0x48 */ nn::Result (*GetActiveChannelCount)(struct nn::audio::server::IAudioDevice*);
    /* 0x50 */ nn::Result (*ListAudioDeviceNameAuto)(struct nn::audio::server::IAudioDevice*);
    /* 0x58 */ nn::Result (*SetAudioDeviceOutputVolumeAuto)(struct nn::audio::server::IAudioDevice*);
    /* 0x60 */ nn::Result (*GetAudioDeviceOutputVolumeAuto)(struct nn::audio::server::IAudioDevice*);
    /* 0x68 */ nn::Result (*GetActiveAudioDeviceNameAuto)(struct nn::audio::server::IAudioDevice*);
    /* 0x70 */ nn::Result (*QueryAudioDeviceInputEvent)(struct nn::audio::server::IAudioDevice*);
    /* 0x78 */ nn::Result (*QueryAudioDeviceOutputEvent)(struct nn::audio::server::IAudioDevice*);
    /* 0x80 */ nn::Result (*GetAudioSystemMasterVolumeSetting)(struct nn::audio::server::IAudioDevice*);
    /* 0x88 */ nn::Result (*ListAudioOutputDeviceName)(struct nn::audio::server::IAudioDevice*);
};

struct nn::audio::server::IAudioDevice {
    /* 0x00 */ nn::audio::server::IAudioDevice::vtbl* __vftable;
};

struct nn::audio::AudioController;

struct nn::audio::AudioController::vtable {
    /* 0x000 */ void (*AddReference)(struct nn::audio::server::IAudioDevice*);
    /* 0x008 */ void (*Release)(struct nn::audio::server::IAudioDevice*);
    /* 0x010 */ void (*GetProxyInfo)(struct nn::audio::server::IAudioDevice*);
    /* 0x018 */ void (*GetInterfaceTypeInfo)(struct nn::audio::server::IAudioDevice*);
    
    /* 0x000 */ void (*GetTargetVolume)(nn::audio::AudioController*);
    /* 0x008 */ void (*SetTargetVolume)(nn::audio::AudioController*);
    /* 0x010 */ void (*GetTargetVolumeMin)(nn::audio::AudioController*);
    /* 0x018 */ void (*GetTargetVolumeMax)(nn::audio::AudioController*);
    /* 0x020 */ void (*IsTargetMute)(nn::audio::AudioController*);
    /* 0x028 */ void (*SetTargetMute)(nn::audio::AudioController*);
    /* 0x030 */ void (*IsTargetConnected)(nn::audio::AudioController*);
    /* 0x038 */ void (*SetDefaultTarget)(nn::audio::AudioController*);
    /* 0x040 */ void (*GetDefaultTarget)(nn::audio::AudioController*);
    /* 0x048 */ void (*GetAudioOutputMode)(nn::audio::AudioController*);
    /* 0x050 */ void (*SetAudioOutputMode)(nn::audio::AudioController*);
    /* 0x058 */ void (*SetForceMutePolicy)(nn::audio::AudioController*);
    /* 0x060 */ void (*GetForceMutePolicy)(nn::audio::AudioController*);
    /* 0x068 */ void (*GetOutputModeSetting)(nn::audio::AudioController*);
    /* 0x070 */ void (*SetOutputModeSetting)(nn::audio::AudioController*);
    /* 0x078 */ void (*SetOutputTarget)(nn::audio::AudioController*);
    /* 0x080 */ void (*SetInputTargetForceEnabled)(nn::audio::AudioController*);
    /* 0x088 */ void (*SetHeadphoneOutputLevelMode)(nn::audio::AudioController*);
    /* 0x090 */ void (*GetHeadphoneOutputLevelMode)(nn::audio::AudioController*);
    /* 0x098 */ void (*AcquireAudioVolumeUpdateEventForPlayReport)(nn::audio::AudioController*);
    /* 0x0A0 */ void (*AcquireAudioOutputDeviceUpdateEventForPlayReport)(nn::audio::AudioController*);
    /* 0x0A8 */ void (*GetAudioOutputTargetForPlayReport)(nn::audio::AudioController*);
    /* 0x0B0 */ void (*NotifyHeadphoneVolumeWarningDisplayedEvent)(nn::audio::AudioController*);
    /* 0x0B8 */ void (*SetSystemOutputMasterVolume)(nn::audio::AudioController*);
    /* 0x0C0 */ void (*GetSystemOutputMasterVolume)(nn::audio::AudioController*);
    /* 0x0C8 */ void (*GetAudioVolumeDataForPlayReport)(nn::audio::AudioController*);
    /* 0x0D0 */ void (*UpdateHeadphoneSettings)(nn::audio::AudioController*);
    /* 0x0D8 */ void (*SetVolumeMappingTableForDev)(nn::audio::AudioController*);
    /* 0x0E0 */ void (*GetAudioOutputChannelCountForPlayReport)(nn::audio::AudioController*);
    /* 0x0E8 */ void (*BindAudioOutputChannelCountUpdateEventForPlayReport)(nn::audio::AudioController*);
    /* 0x0F0 */ void (*SetSpeakerAutoMuteEnabled)(nn::audio::AudioController*);
    /* 0x0F8 */ void (*IsSpeakerAutoMuteEnabled)(nn::audio::AudioController*);
    /* 0x100 */ void (*GetActiveOutputTarget)(nn::audio::AudioController*);
    /* 0x108 */ void (*GetTargetDeviceInfo)(nn::audio::AudioController*);
    /* 0x110 */ void (*AcquireTargetNotification)(nn::audio::AudioController*);
    /* 0x118 */ void (*NotifyAudioOutputTargetForPlayReport)(nn::audio::AudioController*);
    /* 0x120 */ void (*NotifyAudioOutputChannelCountForPlayReport)(nn::audio::AudioController*);
    /* 0x128 */ void (*NotifyUnsupportedUsbOutputDeviceAttachedForPlayReport)(nn::audio::AudioController*);
};

struct nn::audio::detail::AudioSystemManagerForAppletImpl {
    /* 0x00 */ char unk00[0x4];
};

struct nn::audio::detail::AudioSystemManagerForApplet {
    /* 0x00 */ struct nn::audio::detail::AudioSystemManagerForApplet::vtable* __vftable;
    /* 0x08 */ nn::audio::detail::AudioSystemManagerForAppletImpl* impl;
};

struct nn::audio::detail::AudioSystemManagerForApplet::vtable {
    /* 0x00 */ void (*AddReference)(nn::audio::detail::AudioSystemManagerForApplet*);
    /* 0x08 */ void (*Release)(nn::audio::detail::AudioSystemManagerForApplet*);
    /* 0x10 */ void (*GetProxyInfo)(nn::audio::detail::AudioSystemManagerForApplet*);
    /* 0x18 */ void (*GetInterfaceTypeInfo)(nn::audio::detail::AudioSystemManagerForApplet*);
    
    /* 0x20 */ void (*RegisterAppletResourceUserId)(nn::audio::detail::AudioSystemManagerForApplet*);
    /* 0x28 */ void (*UnregisterAppletResourceUserId)(nn::audio::detail::AudioSystemManagerForApplet*);
    /* 0x20 */ void (*RequestSuspendAudio)(nn::audio::detail::AudioSystemManagerForApplet*);
    /* 0x28 */ void (*RequestResumeAudio)(nn::audio::detail::AudioSystemManagerForApplet*);
    /* 0x30 */ void (*GetAudioOutputProcessMasterVolume)(nn::audio::detail::AudioSystemManagerForApplet*);
    /* 0x28 */ void (*SetAudioOutputProcessMasterVolume)(nn::audio::detail::AudioSystemManagerForApplet*);
    /* 0x40 */ void (*GetAudioInputProcessMasterVolume)(nn::audio::detail::AudioSystemManagerForApplet*);
    /* 0x28 */ void (*SetAudioInputProcessMasterVolume)(nn::audio::detail::AudioSystemManagerForApplet*);
    /* 0x50 */ void (*GetAudioOutputProcessRecordVolume)(nn::audio::detail::AudioSystemManagerForApplet*);
    /* 0x28 */ void (*SetAudioOutputProcessRecordVolume)(nn::audio::detail::AudioSystemManagerForApplet*);
};

// =================== OS ===================

struct nn::sf::OutBuffer {
    /* 0x00 */ void* pointer;
    /* 0x08 */ u64 size;
}; // size = 0x10

struct nn::sf::InBuffer {
    /* 0x00 */ void* pointer;
    /* 0x08 */ u64 size;
}; // size = 0x10

struct nn::os::TimeSpan {
    /* 0x00 */ u64 time;
}; // size = 0x8

struct nn::os::detail::InternalCriticalSection {
    /* 0x00 */ u32 image;
}; // size = 0x4

struct nn::os::detail::InternalConditionVariable  {
    /* 0x00 */ u32 image;
}; // size = 0x4

struct nn::os::SystemEvent {
    /* 0x00 */ u32 handle;
    /* 0x04 */ bool valid;
    /* 0x05 */ char unk05[0xF];
    /* 0x14 */ u32 unk_14;
}; // size >= 0x18

//struct nn::os::SystemEventType {
//    union {
//        /* 0x00 */ nn::os::EventType event;
//        /* 0x00 */ nn::os::detail::InterProcessEventType;
//    };
//    /* 0x28 */ u8 state;
//    /* 0x29 */ char unk29[0x7];
//}; // size = 0x30

//struct nn::os::EventType {
//    /* 0x00 */ nn::os::EventType* multi_wait_object_list_storage;
//    /* 0x08 */ nn::os::EventType* multi_wait_object_list_storage08;
//    /* 0x10 */ bool signalled;
//    /* 0x11 */ bool initiallySignaled;
//    /* 0x12 */ u8 clear_mode;
//    /* 0x13 */ u8 state;
//    /* 0x14 */ u32 broadcast_counter_low;
//    /* 0x18 */ u32 broadcast_counter_high;
//    /* 0x1C */ nn::os::detail::InternalCriticalSection section;
//    /* 0x20 */ nn::os::detail::InternalConditionVariable conditionVariable;
//    /* 0x24 */ char unk24[0x4];
//}; // size = 0x28

struct nn::os::Mutex {
    /* 0x00 */ char unk00[0x20];
}; // size = 0x20

struct nn::os::SdkMutexType {
    /* 0x00 */ u32 mutex;
}; // size >= 0x4

struct nn::os::SdkRecursiveMutexType {
    /* 0x00 */ u32 mutex;
    /* 0x00 */ u32 unk_04;
}; // size = 0x8

struct nn::os::Thread {
    /* 0x000 */ char unk000[0x1A0];
    /* 0x1A0 */ char* name;
    /* 0x1A8 */ char unk1A8[0x18];
}; // size = 0x1C0

struct nn::os::SemaphoreType {
    /* 0x00 */ char storage[0x28];
}; // size = 0x28

struct nn::os::MultiWaitType {
    /* 0x00 */ bool isInitialised;
    /* 0x01 */ char unk01[0x27];
    /* 0x28 */ nn::os::detail::InternalCriticalSection criticalSection;
    /* 0x2C */ char unk2C[0x4];
}; // size = 0x30

struct nn::os::MultiWaitHolderType {
    /* 0x00 */ nn::os::MultiWaitType multiWait;
    /* 0x30 */ nn::os::SemaphoreType* semaphore;
    /* 0x38 */ u64 userData;
}; // size = 0x40

struct __attribute__((packed)) nn::util::BitArray {
    /* 0x00 */ u64* buffer;
    /* 0x08 */ s32 size;
}; // size = 0x0C

enum EXECUTIONMODE : u32 {
    DSP = 1,
    CPU = 2,
};

enum nn::audio::server::MemoryPoolInfo::Location {
    CPU = 1,
    DSP = 2,
};

// a span-type struct
struct span {
    void* data;
    s64 size;
};

enum nn::psc::PmModuleId {
    /* 0x00 */ Reserved0,
    /* 0x01 */ Reserved1,
    /* 0x02 */ Reserved2,
    /* 0x03 */ Socket,
    /* 0x04 */ Usb,
    /* 0x05 */ Eth,
    /* 0x06 */ Fgm,
    /* 0x07 */ PcvClock,
    /* 0x08 */ PcvVoltage,
    /* 0x09 */ Gpio,
    /* 0x0A */ Pinmux,
    /* 0x0B */ Uart,
    /* 0x0C */ I2c,
    /* 0x0D */ I2cPowerBus,
    /* 0x0E */ Spi,
    /* 0x0F */ Pwm,
    /* 0x10 */ Psm,
    /* 0x11 */ Tc,
    /* 0x12 */ Omm,
    /* 0x13 */ Pcie,
    /* 0x14 */ Lbl,
    /* 0x15 */ Display,
    /* 0x16 */ Multimedia,
    /* 0x17 */ Time17,
    /* 0x18 */ Hid,
    /* 0x19 */ SocketWlan,
    /* 0x1A */ Wlan,
    /* 0x1B */ Fs,
    /* 0x1C */ Audio,
    /* 0x1D */ Tm,
    /* 0x1E */ TmHostIo,
    /* 0x1F */ Bluetooth,
    /* 0x20 */ Bpc,
    /* 0x21 */ Fan,
    /* 0x22 */ Pcm,
    /* 0x23 */ Nfc,
    /* 0x24 */ Apm,
    /* 0x25 */ Btm,
    /* 0x26 */ Nifm,
    /* 0x27 */ GpioLow,
    /* 0x28 */ Npns,
    /* 0x29 */ Lm,
    /* 0x2A */ Bcat,
    /* 0x2B */ Time2B,
    /* 0x2C */ Pctl,
    /* 0x2D */ Erpt,
    /* 0x2E */ Eupld,
    /* 0x2F */ Friends,
    /* 0x30 */ Bgtc,
    /* 0x31 */ Account,
    /* 0x32 */ Sasbus,
    /* 0x33 */ Ntc,
    /* 0x34 */ Idle,
    /* 0x35 */ Tcap,
    /* 0x36 */ PsmLow,
    /* 0x37 */ Ndd,
    /* 0x38 */ Olsc,
    /* 0x39 */ Rtc,
    /* 0x3A */ Unk3A,
    /* 0x3B */ Unk3B,
    /* 0x3C */ Led,
    /* 0x3D */ Ns,
    /* 0x3E */ Unk3E,
    /* 0x3F */ NotificationPresenter,
    /* 0x40 */ Unk40,
    /* 0x41 */ DhcpClient,
    /* 0x65 */ NvHost = 0x65,
    /* 0x69 */ NvDbgSvc = 0x69,
    /* 0x6A */ Tspm = 0x6A,
    /* 0x7F */ Spsm = 0x7F,
};

enum nn::psc::PmState {
    /* 0 */ FullAwake,                   // Everything is awake.
    /* 1 */ MinimumAwake,                // Preparing to transition to awake.
    /* 2 */ SleepReady,                  // Preparing to transition to sleep.
    /* 3 */ EssentialServicesSleepReady, // Critical services are ready to sleep.
    /* 4 */ EssentialServicesAwake,      // Critical services are ready to wake up.
    /* 5 */ ShutdownReady,               // Preparing to transition to shutdown.
    /* 6 */ Invalid,                     // Default state. 
};

struct nn::bluetooth::IBluetoothDriver {
    struct nn::bluetooth::IBluetoothDriver::vtable* __vftable;
};

struct nn::bluetooth::IBluetoothDriver::vtable {
    /* 0x00 */ void (*AddReference)(nn::bluetooth::IBluetoothDriver*);
    /* 0x08 */ void (*Release)(nn::bluetooth::IBluetoothDriver*);
    /* 0x10 */ void (*GetProxyInfo)(nn::bluetooth::IBluetoothDriver*);
    /* 0x18 */ void (*GetInterfaceTypeInfo)(nn::bluetooth::IBluetoothDriver*);

    /* 0x020 */ void (*InitializeBluetoothDriver)(nn::bluetooth::IBluetoothDriver*);
    /* 0x028 */ void (*InitializeBluetooth)(nn::bluetooth::IBluetoothDriver*);
    /* 0x030 */ void (*EnableBluetooth)(nn::bluetooth::IBluetoothDriver*);
    /* 0x038 */ void (*DisableBluetooth)(nn::bluetooth::IBluetoothDriver*);
    /* 0x040 */ void (*FinalizeBluetooth)(nn::bluetooth::IBluetoothDriver*);
    /* 0x048 */ void (*GetAdapterProperties)(nn::bluetooth::IBluetoothDriver*);
    /* 0x050 */ void (*GetAdapterProperty)(nn::bluetooth::IBluetoothDriver*);
    /* 0x058 */ void (*SetAdapterProperty)(nn::bluetooth::IBluetoothDriver*);
    /* 0x060 */ void (*StartInquiry)(nn::bluetooth::IBluetoothDriver*);
    /* 0x068 */ void (*StopInquiry)(nn::bluetooth::IBluetoothDriver*);
    /* 0x070 */ void (*CreateBond)(nn::bluetooth::IBluetoothDriver*);
    /* 0x078 */ void (*RemoveBond)(nn::bluetooth::IBluetoothDriver*);
    /* 0x080 */ void (*CancelBond)(nn::bluetooth::IBluetoothDriver*);
    /* 0x088 */ void (*RespondToPinRequest)(nn::bluetooth::IBluetoothDriver*);
    /* 0x090 */ void (*RespondToSspRequest)(nn::bluetooth::IBluetoothDriver*);
    /* 0x098 */ void (*GetEventInfo)(nn::bluetooth::IBluetoothDriver*);
    /* 0x0A0 */ void (*InitializeHid)(nn::bluetooth::IBluetoothDriver*);
    /* 0x0A8 */ void (*OpenHidConnection)(nn::bluetooth::IBluetoothDriver*);
    /* 0x0B0 */ void (*CloseHidConnection)(nn::bluetooth::IBluetoothDriver*);
    /* 0x0B8 */ void (*WriteHidData)(nn::bluetooth::IBluetoothDriver*);
    /* 0x0C0 */ void (*WriteHidData2)(nn::bluetooth::IBluetoothDriver*);
    /* 0x0C8 */ void (*SetHidReport)(nn::bluetooth::IBluetoothDriver*);
    /* 0x0D0 */ void (*GetHidReport)(nn::bluetooth::IBluetoothDriver*);
    /* 0x0D8 */ void (*TriggerConnection)(nn::bluetooth::IBluetoothDriver*);
    /* 0x0E0 */ void (*AddPairedDeviceInfo)(nn::bluetooth::IBluetoothDriver*);
    /* 0x0E8 */ void (*GetPairedDeviceInfo)(nn::bluetooth::IBluetoothDriver*);
    /* 0x0F0 */ void (*FinalizeHid)(nn::bluetooth::IBluetoothDriver*);
    /* 0x0F8 */ void (*GetHidEventInfo)(nn::bluetooth::IBluetoothDriver*);
    /* 0x100 */ void (*SetTsi)(nn::bluetooth::IBluetoothDriver*);
    /* 0x108 */ void (*EnableBurstMode)(nn::bluetooth::IBluetoothDriver*);
    /* 0x110 */ void (*SetZeroRetransmission)(nn::bluetooth::IBluetoothDriver*);
    /* 0x118 */ void (*EnableMcMode)(nn::bluetooth::IBluetoothDriver*);
    /* 0x120 */ void (*EnableLlrScan)(nn::bluetooth::IBluetoothDriver*);
    /* 0x128 */ void (*DisableLlrScan)(nn::bluetooth::IBluetoothDriver*);
    /* 0x130 */ void (*EnableRadio)(nn::bluetooth::IBluetoothDriver*);
    /* 0x138 */ void (*SetVisibility)(nn::bluetooth::IBluetoothDriver*);
    /* 0x140 */ void (*EnableTbfcScan)(nn::bluetooth::IBluetoothDriver*);
    /* 0x148 */ void (*RegisterHidReportEvent)(nn::bluetooth::IBluetoothDriver*);
    /* 0x150 */ void (*GetHidReportEventInfo)(nn::bluetooth::IBluetoothDriver*);
    /* 0x158 */ void (*GetLatestPlr)(nn::bluetooth::IBluetoothDriver*);
    /* 0x160 */ void (*GetPendingConnections)(nn::bluetooth::IBluetoothDriver*);
    /* 0x168 */ void (*GetChannelMap)(nn::bluetooth::IBluetoothDriver*);
    /* 0x170 */ void (*EnableTxPowerBoostSetting)(nn::bluetooth::IBluetoothDriver*);
    /* 0x178 */ void (*IsTxPowerBoostSettingEnabled)(nn::bluetooth::IBluetoothDriver*);
    /* 0x180 */ void (*EnableAfhSetting)(nn::bluetooth::IBluetoothDriver*);
    /* 0x188 */ void (*IsAfhSettingEnabled)(nn::bluetooth::IBluetoothDriver*);
    /* 0x190 */ void (*InitializeBle)(nn::bluetooth::IBluetoothDriver*);
    /* 0x198 */ void (*EnableBle)(nn::bluetooth::IBluetoothDriver*);
    /* 0x1A0 */ void (*DisableBle)(nn::bluetooth::IBluetoothDriver*);
    /* 0x1A8 */ void (*FinalizeBle)(nn::bluetooth::IBluetoothDriver*);
    /* 0x1B0 */ void (*SetBleVisibility)(nn::bluetooth::IBluetoothDriver*);
    /* 0x1B8 */ void (*SetBleConnectionParameter)(nn::bluetooth::IBluetoothDriver*);
    /* 0x1C0 */ void (*SetBleDefaultConnectionParameter)(nn::bluetooth::IBluetoothDriver*);
    /* 0x1C8 */ void (*SetBleAdvertiseData)(nn::bluetooth::IBluetoothDriver*);
    /* 0x1D0 */ void (*SetBleAdvertiseParameter)(nn::bluetooth::IBluetoothDriver*);
    /* 0x1D8 */ void (*StartBleScan)(nn::bluetooth::IBluetoothDriver*);
    /* 0x1E0 */ void (*StopBleScan)(nn::bluetooth::IBluetoothDriver*);
    /* 0x1E8 */ void (*AddBleScanFilterCondition)(nn::bluetooth::IBluetoothDriver*);
    /* 0x1F0 */ void (*DeleteBleScanFilterCondition)(nn::bluetooth::IBluetoothDriver*);
    /* 0x1F8 */ void (*DeleteBleScanFilter)(nn::bluetooth::IBluetoothDriver*);
    /* 0x200 */ void (*ClearBleScanFilters)(nn::bluetooth::IBluetoothDriver*);
    /* 0x208 */ void (*EnableBleScanFilter)(nn::bluetooth::IBluetoothDriver*);
    /* 0x210 */ void (*RegisterGattClient)(nn::bluetooth::IBluetoothDriver*);
    /* 0x218 */ void (*UnregisterGattClient)(nn::bluetooth::IBluetoothDriver*);
    /* 0x220 */ void (*UnregisterAllGattClients)(nn::bluetooth::IBluetoothDriver*);
    /* 0x228 */ void (*ConnectGattServer)(nn::bluetooth::IBluetoothDriver*);
    /* 0x230 */ void (*CancelConnectGattServer)(nn::bluetooth::IBluetoothDriver*);
    /* 0x238 */ void (*DisconnectGattServer)(nn::bluetooth::IBluetoothDriver*);
    /* 0x240 */ void (*GetGattAttribute)(nn::bluetooth::IBluetoothDriver*);
    /* 0x248 */ void (*GetGattService)(nn::bluetooth::IBluetoothDriver*);
    /* 0x250 */ void (*ConfigureAttMtu)(nn::bluetooth::IBluetoothDriver*);
    /* 0x258 */ void (*RegisterGattServer)(nn::bluetooth::IBluetoothDriver*);
    /* 0x260 */ void (*UnregisterGattServer)(nn::bluetooth::IBluetoothDriver*);
    /* 0x268 */ void (*ConnectGattClient)(nn::bluetooth::IBluetoothDriver*);
    /* 0x270 */ void (*DisconnectGattClient)(nn::bluetooth::IBluetoothDriver*);
    /* 0x278 */ void (*AddGattService)(nn::bluetooth::IBluetoothDriver*);
    /* 0x280 */ void (*EnableGattService)(nn::bluetooth::IBluetoothDriver*);
    /* 0x288 */ void (*AddGattCharacteristic)(nn::bluetooth::IBluetoothDriver*);
    /* 0x290 */ void (*AddGattDescriptor)(nn::bluetooth::IBluetoothDriver*);
    /* 0x298 */ void (*GetBleManagedEventInfo)(nn::bluetooth::IBluetoothDriver*);
    /* 0x2A0 */ void (*GetGattFirstCharacteristic)(nn::bluetooth::IBluetoothDriver*);
    /* 0x2A8 */ void (*GetGattNextCharacteristic)(nn::bluetooth::IBluetoothDriver*);
    /* 0x2B0 */ void (*GetGattFirstDescriptor)(nn::bluetooth::IBluetoothDriver*);
    /* 0x2B8 */ void (*GetGattNextDescriptor)(nn::bluetooth::IBluetoothDriver*);
    /* 0x2C0 */ void (*RegisterGattManagedDataPath)(nn::bluetooth::IBluetoothDriver*);
    /* 0x2C8 */ void (*UnregisterGattManagedDataPath)(nn::bluetooth::IBluetoothDriver*);
    /* 0x2D0 */ void (*RegisterGattHidDataPath)(nn::bluetooth::IBluetoothDriver*);
    /* 0x2D8 */ void (*UnregisterGattHidDataPath)(nn::bluetooth::IBluetoothDriver*);
    /* 0x2E0 */ void (*RegisterGattDataPath)(nn::bluetooth::IBluetoothDriver*);
    /* 0x2E8 */ void (*UnregisterGattDataPath)(nn::bluetooth::IBluetoothDriver*);
    /* 0x2F0 */ void (*ReadGattCharacteristic)(nn::bluetooth::IBluetoothDriver*);
    /* 0x2F8 */ void (*ReadGattDescriptor)(nn::bluetooth::IBluetoothDriver*);
    /* 0x300 */ void (*WriteGattCharacteristic)(nn::bluetooth::IBluetoothDriver*);
    /* 0x308 */ void (*WriteGattDescriptor)(nn::bluetooth::IBluetoothDriver*);
    /* 0x310 */ void (*RegisterGattNotification)(nn::bluetooth::IBluetoothDriver*);
    /* 0x318 */ void (*UnregisterGattNotification)(nn::bluetooth::IBluetoothDriver*);
    /* 0x320 */ void (*GetLeHidEventInfo)(nn::bluetooth::IBluetoothDriver*);
    /* 0x328 */ void (*RegisterBleHidEvent)(nn::bluetooth::IBluetoothDriver*);
    /* 0x330 */ void (*SetBleScanParameter)(nn::bluetooth::IBluetoothDriver*);
    /* 0x338 */ void (*MoveToSecondaryPiconet)(nn::bluetooth::IBluetoothDriver*);
    /* 0x340 */ void (*IsBluetoothEnabled)(nn::bluetooth::IBluetoothDriver*);
    /* 0x348 */ void (*AcquireAudioEvent)(nn::bluetooth::IBluetoothDriver*);
    /* 0x350 */ void (*GetAudioEventInfo)(nn::bluetooth::IBluetoothDriver*);
    /* 0x358 */ void (*OpenAudioConnection)(nn::bluetooth::IBluetoothDriver*);
    /* 0x360 */ void (*CloseAudioConnection)(nn::bluetooth::IBluetoothDriver*);
    /* 0x368 */ void (*OpenAudioOut)(nn::bluetooth::IBluetoothDriver*);
    /* 0x370 */ void (*CloseAudioOut)(nn::bluetooth::IBluetoothDriver*);
    /* 0x378 */ void (*AcquireAudioOutStateChangedEvent)(nn::bluetooth::IBluetoothDriver*);
    /* 0x380 */ void (*StartAudioOut)(nn::bluetooth::IBluetoothDriver*);
    /* 0x388 */ void (*StopAudioOut)(nn::bluetooth::IBluetoothDriver*);
    /* 0x390 */ void (*GetAudioOutState)(nn::bluetooth::IBluetoothDriver*);
    /* 0x398 */ void (*GetAudioOutFeedingCodec)(nn::bluetooth::IBluetoothDriver*);
    /* 0x3A0 */ void (*GetAudioOutFeedingParameter)(nn::bluetooth::IBluetoothDriver*);
    /* 0x3A8 */ void (*AcquireAudioOutBufferAvailableEvent)(nn::bluetooth::IBluetoothDriver*);
    /* 0x3B0 */ void (*SendAudioData)(nn::bluetooth::IBluetoothDriver*);
    /* 0x3B8 */ void (*AcquireAudioControlInputStateChangedEvent)(nn::bluetooth::IBluetoothDriver*);
    /* 0x3C0 */ void (*GetAudioControlInputState)(nn::bluetooth::IBluetoothDriver*);
    /* 0x3C8 */ void (*AcquireAudioConnectionStateChangedEvent)(nn::bluetooth::IBluetoothDriver*);
    /* 0x3D0 */ void (*GetConnectedAudioDevice)(nn::bluetooth::IBluetoothDriver*);
    /* 0x3D8 */ void (*CloseAudioControlInput)(nn::bluetooth::IBluetoothDriver*);
    /* 0x3E0 */ void (*RegisterAudioControlNotification)(nn::bluetooth::IBluetoothDriver*);
    /* 0x3E8 */ void (*SendAudioControlPassthroughCommand)(nn::bluetooth::IBluetoothDriver*);
    /* 0x3F0 */ void (*SendAudioControlSetAbsoluteVolumeCommand)(nn::bluetooth::IBluetoothDriver*);
    /* 0x3F8 */ void (*AcquireAudioSinkVolumeLocallyChangedEvent)(nn::bluetooth::IBluetoothDriver*);
    /* 0x400 */ void (*AcquireAudioSinkVolumeUpdateRequestCompletedEvent)(nn::bluetooth::IBluetoothDriver*);
    /* 0x408 */ void (*GetAudioSinkVolume)(nn::bluetooth::IBluetoothDriver*);
    /* 0x410 */ void (*RequestUpdateAudioSinkVolume)(nn::bluetooth::IBluetoothDriver*);
    /* 0x418 */ void (*IsAudioSinkVolumeSupported)(nn::bluetooth::IBluetoothDriver*);
    /* 0x420 */ void (*IsManufacturingMode)(nn::bluetooth::IBluetoothDriver*);
    /* 0x428 */ void (*EmulateBluetoothCrash)(nn::bluetooth::IBluetoothDriver*);
    /* 0x430 */ void (*GetBleChannelMap)(nn::bluetooth::IBluetoothDriver*);
};
