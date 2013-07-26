

#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>
#include "MediaPlayerInterface.h"



namespace mango
{
	enum{
		MODE_PLAY_ORDER=0,
		MODE_PLAY_LOOP,
		MODE_PLAY_RANDOM,
		MDOE_PLAY_REPEAT
	};
	
	class Playinglist{

		public:
			particle::MediaPlayerInterface*  mParticleplayer;
			mediainfo *mplaylist;
			int len;
			int mCurrent;
			int mMax;
			int playMode;
			int mGapless;
			int inPause;
			Playinglist();
			~Playinglist();
			mediainfo *getPlayingItem();
			mediainfo *getItem(int index);
			void initPlayintList();
			int playMediaInfo(mediainfo *info);
			int isItemExsit(mediainfo *info);
			void moveToLast();
			int moveToNext();
			int moveToPrev();
			void moveToPosition(int pos);
			int moveRandom();		
			int  startPlay();
			void playNext();
			void playPrev(){if(moveToPrev())startPlay();}

			void playPauseOrStart();
			void callbackPlay();
			void addItem(mediainfo *item);
			int getDuration();
			int getCurrent();
			int getCount();
			int isPlaying();
			void setPlayMode(int mode);
			int getPlayMode(){return playMode;}
			void setGapless(int gapless);
			int getGapless(){return mGapless;}
			void setEq(int *val);
			void setEqBandLevel(int index,int val);
			void getAudioInfo(int *);
			int randomInt(int n);
			void PlayerInit();
			void AudioEqualizerEnable(int enable);
			void seekTo(int n){if(mParticleplayer!=NULL)	mParticleplayer->seekTo(n);}
			static void playerCallback(void* calldata, int evnet, int param0, int param1);
	};		
	extern Playinglist *mPlayinglist;

};


