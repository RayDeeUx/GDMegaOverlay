#pragma once

#include <cocos2d.h>
#include <vector>

namespace Macrobot
{
	class Action
	{
	public:
		double frame;
		int key;
		bool press;
	};

	class PlayerCheckpoint
	{
	public:
		double yVel;
		double xVel;
		float xPos;
		float yPos;
		float rotation;

		void apply(cocos2d::CCNode* player);
		void fromPlayer(cocos2d::CCNode* player);
	};

	struct CheckpointData
	{
		double time;
		PlayerCheckpoint p1;
		PlayerCheckpoint p2;
	};

	inline float framerate = 60.f;
	inline int playerMode = -1;

	inline double frame = 0;
	inline unsigned int actionIndex = 0;

	inline cocos2d::CCNode* playerObject1 = nullptr;
	inline cocos2d::CCNode* playerObject2 = nullptr;

	inline char macroName[50];

	inline std::vector<Action> actions;

	inline bool(__thiscall* playerObjectPushButton)(void*, int);
	bool __fastcall playerObjectPushButtonHook(void* self, void*, int btn);

	inline bool(__thiscall* playerObjectReleaseButton)(void*, int);
	bool __fastcall playerObjectReleaseButtonHook(void* self, void*, int btn);

	inline bool(__thiscall* playerObjectLoadFromCheckpoint)(void*, void*);
	bool __fastcall playerObjectLoadFromCheckpointHook(void* self, void*, void* checkpoint);

	inline void(__thiscall* GJBaseGameLayerUpdate)(void*, float);
	void __fastcall GJBaseGameLayerUpdateHook(void* self, void*, float dt);

	inline int(__thiscall* playLayerResetLevel)(void*);
	int __fastcall playLayerResetLevelHook(void* self, void*);

	inline void(__thiscall* playLayerLoadFromCheckpoint)(void*, void* checkpoint);
	void __fastcall playLayerLoadFromCheckpointHook(void* self, void*, void* checkpoint);

	inline void*(__thiscall* checkpointObjectInit)(void*);
	void* __fastcall checkpointObjectInitHook(void* self, void*);

	void initHooks();

	void recordAction(int key, double frame, bool press);

	void save(std::string file);
	void load(std::string file);

	void drawWindow();
};