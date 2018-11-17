#include <xboxkrnl/xboxkrnl.h>
#include <hal/video.h>

extern int main (int argc, char **argv);

void XboxCRTEntry ()
{
    XVideoSetMode(640, 480, 32, REFRESH_DEFAULT);

    char *_argv = 0;
    main(0, &_argv);

    HalReturnToFirmware(HalQuickRebootRoutine);
}
