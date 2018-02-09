#include "AssetManager.h"
#include "ECS\Components.h"

AssetManager::AssetManager(Manager* man) : manager(man)
{
}

AssetManager::~AssetManager()
{}

void AssetManager::CreateProjectile(Vector2D pos, int rng, int sp, std::string id)
{
	auto& proj(manager->addEntity());
	proj.addComponent<TransformComponent>(pos.x, pos.y, 32, 32, 1);
	proj.getComponent<TransformComponent>().velocity.x = sp;
	proj.addComponent<SpriteComponent>(id, false);
	proj.addComponent<Projectile>(rng, sp);
	proj.addComponent<ColliderComponent>("projectile");
	proj.addGroup(Game::groupProjectiles);
}

void AssetManager::AddTexture(std::string id, const char* path)
{
	textures.emplace(id, TextureManager::LoadTexture(path));
}

SDL_Texture* AssetManager::GetTexture(std::string id)
{
	return textures[id];
}

void AssetManager::AddFont(std::string id, std::string path, int fontSize)
{
	fonts.emplace(id, TTF_OpenFont(path.c_str(), fontSize));
}

TTF_Font* AssetManager::GetFont(std::string id)
{
	return fonts[id];
}
