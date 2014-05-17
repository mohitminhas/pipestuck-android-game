//
//  config.h
//  PipeStuck
//
//
//

#ifndef PipeStuck_config_h
#define PipeStuck_config_h


#define FireUpInterval 0.05 // Time for jetpack boy to move to the top when tapped

#define ThrustOffset 50 //The jumping value of the jetpack boy is 50px
#define ThrustDura 0.5 // The jumping return time of the jetpack boy is 0.5sec

#define LandPos 127 // The position of the land placed from the bottom to its center points.

// It is the time in seconds when to add new pipes on the right of the screen, depends on the speed and garbade collection of unrequired objects.
#define GapAddSpidersAndCrows 2
#define kHoleBetweenPipe 80


#define Landfragments 15 // on every frame update 15px movements to left is done to the land
#define kParallaxDura 0.3 //Duration after when the land is moved to the left.

#define SoundTap "Jetpack.mp3"
#define SoundHit "Strike.mp3"
#define SoundPoint "Score.mp3"

#endif
