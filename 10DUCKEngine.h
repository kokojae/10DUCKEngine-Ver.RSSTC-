#pragma once

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define WINDOWED false

// Component
#include "BoxCollider.h"
#include "TextureInfo.h"

// GameObject
// Base
#include "GameObject.h"
#include "Text.h"
// Character
#include "Player.h"
// Weapon
// Base
#include "Weapon.h"
// Bullet
#include "Bullet.h"
// Weapons
#include "Shotgun.h"
// Scene
// Title
#include "TitleBG.h"
#include "TitleStartBtn.h"
#include "TitleOptionBtn.h"
// Option
#include "OptionBG.h"
#include "OptionRetBtn.h"
// Stage
#include "Background.h"
#include "Block.h"

// Manager
#include "Camera.h"
#include "GraphicManager.h"
#include "Layer.h"
#include "MouseInput.h"
#include "ObjectManager.h"
#include "SceneManager.h"
#include "SoundManager.h"
#include "TextureManager.h"

//콘솔창 띄우기
//#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console") 

#define COLOR(a,r,g,b) (D3DCOLOR_ARGB(a, r, g, b))
#define TRANSPARENCY_COLOR(a) (D3DCOLOR_ARGB(a, 128, 128, 128))