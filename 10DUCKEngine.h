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
//Scene
#include "TitleBG.h"
// Object
#include "Block.h"
#include "Player.h"

// Manager
#include "Camera.h"
#include "GraphicManager.h"
#include "Layer.h"
#include "ObjectManager.h"
#include "SceneManager.h"
#include "SoundManager.h"
#include "TextureManager.h"

#define COLOR(a,r,g,b) (D3DCOLOR_ARGB(a, r, g, b))
#define TRANSPARENCY_COLOR(a) (D3DCOLOR_ARGB(a, 128, 128, 128))