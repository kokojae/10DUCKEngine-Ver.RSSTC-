#include "DXUT.h"
#include "Block.h"
#include "10DUCKEngine.h"

Block::Block()
{
}

Block::~Block()
{
}

void Block::Init()
{
	SetTexture(L"resorce/background/stage/stage1/block.png", { 960, 55 });
	SetCollider({ 960, 55 });
	collider.layer = Layer::BLOCK;
}

void Block::Update()
{
}
