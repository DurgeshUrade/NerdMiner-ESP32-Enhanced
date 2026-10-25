#include "display.h"

#if defined(OLED_SSD1306_128X64_DISPLAY)
DisplayDriver *currentDisplayDriver = &ssd1306DisplayDriver;
#elif defined(NO_DISPLAY)
DisplayDriver *currentDisplayDriver = &noDisplayDriver;
#elif defined(M5STACK_DISPLAY)
DisplayDriver *currentDisplayDriver = &m5stackDisplayDriver;
#elif defined(WT32_DISPLAY)
DisplayDriver *currentDisplayDriver = &wt32DisplayDriver;
#elif defined(LED_DISPLAY)
DisplayDriver *currentDisplayDriver = &ledDisplayDriver;
#elif defined(OLED_042_DISPLAY)
DisplayDriver *currentDisplayDriver = &oled042DisplayDriver;
#elif defined(T_DISPLAY)
DisplayDriver *currentDisplayDriver = &tDisplayDriver;
#elif defined(AMOLED_DISPLAY)
DisplayDriver *currentDisplayDriver = &amoledDisplayDriver;
#elif defined(DONGLE_DISPLAY)
DisplayDriver *currentDisplayDriver = &dongleDisplayDriver;
#elif defined(V1_DISPLAY)
DisplayDriver *currentDisplayDriver = &tDisplayV1Driver;
#elif defined(M5STICKC_DISPLAY)
DisplayDriver *currentDisplayDriver = &m5stickCDisplayDriver;
#elif defined(M5STICKCPLUS_DISPLAY)
DisplayDriver *currentDisplayDriver = &m5stickCPlusDriver;
#elif defined(T_HMI_DISPLAY)
DisplayDriver *currentDisplayDriver = &t_hmiDisplayDriver;
#elif defined(ST7735S_DISPLAY)
DisplayDriver *currentDisplayDriver = &sp_kcDisplayDriver;
#endif


// Initialize the display
void initDisplay()
{
  currentDisplayDriver->initDisplay();
}

// Alternate screen state
void alternateScreenState()
{
  currentDisplayDriver->alternateScreenState();
}

// Alternate screen rotation
void alternateScreenRotation()
{
  currentDisplayDriver->alternateScreenRotation();
}

// Draw the loading screen
void drawLoadingScreen()
{
  currentDisplayDriver->loadingScreen();
}

// Draw the setup screen
void drawSetupScreen()
{
  currentDisplayDriver->setupScreen();
}

// Reset the current cyclic screen to the first one
void resetToFirstScreen()
{
  currentDisplayDriver->current_cyclic_screen = 0;
}

// Switches to the next cyclic screen without drawing it
void switchToNextScreen()
{
  currentDisplayDriver->current_cyclic_screen = (currentDisplayDriver->current_cyclic_screen + 1) % currentDisplayDriver->num_cyclic_screens;
}

// Draw the current cyclic screen
void drawCurrentScreen(unsigned long mElapsed)
{
  currentDisplayDriver->cyclic_screens[currentDisplayDriver->current_cyclic_screen](mElapsed);
}

// Animate the current cyclic screen
void animateCurrentScreen(unsigned long frame)
{
  currentDisplayDriver->animateCurrentScreen(frame);
}

// Do LED stuff
void doLedStuff(unsigned long frame)
{
  currentDisplayDriver->doLedStuff(frame);
}
