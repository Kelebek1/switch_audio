## Switch Audio sysmodule stuff

This repo contains structs and IDA dbs (IDA 7.6+) for the Switch audio sysmodule. It's FAR from complete and quite messy, some things may be wrong etc etc, so take it all with a grain of salt. This was the stuff I used to write the audio impl in Yuzu.

audio_xx.x.x are the firmware sysmodules with that respective version.
dsp_xx.x.x are for the ADSP binary stored within the sysmodule.
sdk.rar contains the SDK DBs for their given versions, these are what I used as a base to help fill out the sysmodule symbols and structs.

I did all the work on the 13.2.1 versions, so those are the most complete, for 14 I just import the 13.2.1 and check the differences, so it's less complete than 13 and some of the bindiff checked symbols are wrong. Use the 13 versions unless you need something explicitly from 14.

### ADSP

There's a 32-bit binary stored within the audio sysmodule which is launched at startup. This binary is the adsp which comes from nVidia's L4T (Linux4Tegra) packages. It hosts various apps which developers can write for it, and they communicate with the main sysmodule via mailboxes. I've included the base adsp in the adsp folder. **It doesn't contain any Nintendo code, it's just the base elf from nVidia**, it includes symbols and structs which can be used as a reference, since the adsp inside the sysmodule is stripped.

Here's a couple ways too get the ADSP in a sysmodule without symbols (In my DBs it's inside the DoFirmwareLoadImpl function):
 - Look at the segments list and it should be the 5th one (after .rodata)
 - Search for 0xC0C99, which error is thrown when the adsp fails to launch, so just scroll up from that and the function call to launch the ADSP should be right above it. The call takes the start/end pointers of the ADSP code, so you can dump it from there.


 The ADSP itself has a function which sets up and prints the segments (platform_remap_mappings) so you can search for 0x80300000 or search for "text" and you'll find the function even without symbols. So you can then add those segments to the ADSP in IDA if you want.

 The `apps_init` function sets up the registered apps, the linked data contains the app info for each app. There's the app name, an init function, and the main function.
 Nintendo have 3 apps:
  - gmix. This app is what actually deals with audio hardware I think. It recieves samples from the AudioRenderer app and also gets messages from the sysmodule via AudioRenderSession. I haven't done much RE of this app, and I don't understand it very well. Great area for more RE if anyone wants.
  - AudioRenderer. This app interacts with the audren service in the sysmodule. It receives a command list from audren and processes the commands, sending the resulting audio samples through gmix.
  - OpusDecoder. The ADSP contains libopus and deals with Opus audio stuff from the hwopus service. Haven't RE'd this one either.

`<app>_Main` are the entry points for that app, so AudioRender_Main is the place to go to start looking at how the audio renderer works etc. Some of these functions are also included the sdk which is very useful, like CommandListProcessor::Process which is the main audio renderer function which processes the command list, along with all the of individual command functions. I've found it easier to look at the 64-bit SDK side to understand the commands rather than the 32-bit ADSP ones, but it's nice to be able to look at the same functions compiled two different ways to help understand them. For that Command Process function in particular, it's a massive switch of all commands, so you need to re-type commandbuffer to the specific command you're looking at. Variables also overlap with different purposes in each, so you'll probably want to rename variables.

### Structs

The structs folder contains all the structs I've created in a few big C headers. `audio.h` is the main header file, and includes everything else except `dsp.h`, which is for adsp-specific things. The normal way I use these is to edits whichever struct, and then use ctrl+f9 in IDA, and select `audio.h`. All the structs will be updated and stuff, then just hit f5 to re-decompile whichever function you're looking at and the changes will apply.
You can use these structs alone without needing the IDA DBs, although when first importing there may be some errors with missing symbols etc because of the order everything is laid out in the header. Try using ctrl+f9 a couple times in a row, if the number of errors don't go down, then check the output, you'll probably just need to throw the `struct` keyword on some struct members which use structs that are defined below them. Everything is there though.
My DBs do contain some outdated structs since I changed struct names and stuff while working on the RE, e.g `nn::audio::dsp::ReverbCommand` vs `nn::audio::ReverbCommand` where the second one is the current and most updated one, as it's currently named in audio.h. Be careful of that kind of thing.

Some structs have firmware/sdk versions when they differ. DelayLine and DelayLineSdk for example, make sure you use the Sdk one for the SDK, and the other for firmware. AudioRenderSystem is one I named like an idiot, where AudioRenderSystem is for the SDK, and AudioRenderSystemS is for firmware. I started working via SDK first, and then when I came to add the firmware version I just added an "S" for SDK even though it's the toher way around. It was dumb but whatever, I commented which is which in the header file.

The structs are updated to firmware 15 currently, so using them directly on firmware 13 for example will be wrong and give you some wrong struct sizes. Unfortunately I didn't keep older firmware versions as separate headers as I should have, but those versions are still available via the DBs so you can dump them from there.

If you have any questions or stuff doesn't work then you can message me on Discord, Maide on Yuzu's server.
