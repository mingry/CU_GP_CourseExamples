
#include "TextureManager.h"
#include "SDL_image.h"
#include <iostream>
#include <string>

extern SDL_Renderer* g_renderer;


TextureManager* TextureManager::instance_ = 0 ;


void TextureManager::CreateInstance()
{
	if ( instance_ != 0  ) return;
	instance_ = new TextureManager();
}

void TextureManager::DestroyInstance()
{
	if ( instance_ == 0  ) return;

	std::map<std::string, SDL_Texture*>::iterator iter = instance_->texture_map_.begin();
	while ( iter != instance_->texture_map_.end() )
	{
		SDL_DestroyTexture(iter->second);
		iter++;
	}
	delete instance_;
	instance_ = 0;
}

TextureManager* TextureManager::GetSingleton()
{
	return instance_;
}

bool TextureManager::LoadTexture(std::string texture_id, std::string file_name)
{
	SDL_Surface* temp_surface = IMG_Load(file_name.c_str());
	if(temp_surface == 0)
	{
		return false;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(g_renderer, temp_surface);
	SDL_Rect rect;
	rect.x = rect.y = 0;
	rect.w = temp_surface->w;
	rect.h = temp_surface->h;

	SDL_FreeSurface(temp_surface);
	
	// everything went ok, add the texture to our list
	if(texture != 0)
	{
		texture_map_[texture_id] = texture;
		AddSpriteRect(texture_id, rect.x, rect.y, rect.w, rect.h);
		return true;
	}
	
	// reaching here means something went wrong
	return false;
}

bool TextureManager::LoadTexture(std::string texture_id, std::string file_name, unsigned char color_key_r, unsigned char color_key_g, unsigned char color_key_b)
{
	SDL_Surface* temp_surface = IMG_Load(file_name.c_str());
	if(temp_surface == 0)
	{
		return false;
	}
	SDL_SetColorKey(temp_surface, 1, SDL_MapRGB(temp_surface->format, color_key_r, color_key_g, color_key_b));

	SDL_Texture* texture = SDL_CreateTextureFromSurface(g_renderer, temp_surface);
	SDL_Rect rect;
	rect.x = rect.y = 0;
	rect.w = temp_surface->w;
	rect.h = temp_surface->h;

	SDL_FreeSurface(temp_surface);
	
	// everything went ok, add the texture to our list
	if(texture != 0)
	{
		texture_map_[texture_id] = texture;
		AddSpriteRect(texture_id, rect.x, rect.y, rect.w, rect.h);
		return true;
	}
	
	// reaching here means something went wrong
	return false;
}


void TextureManager::AddSpriteRect(std::string sprite_id, int x, int y, int w, int h)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	sprite_rects_[sprite_id] = rect;
}



void TextureManager::DrawSprite(std::string texture_id)
{
	DrawSprite(texture_id, texture_id, 0, 0);
}

void TextureManager::DrawSprite(std::string texture_id, std::string sprite_id, int x, int y)
{
	SDL_Rect src_rect = sprite_rects_[sprite_id];
	SDL_Rect dest_rect;
	dest_rect.x = x;
	dest_rect.y = y;
	dest_rect.w = src_rect.w;
	dest_rect.h = src_rect.h;
	SDL_RenderCopy(g_renderer, texture_map_[texture_id], &src_rect,	&dest_rect);
}
