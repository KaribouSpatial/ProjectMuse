/////////////////////////////////////////////////////
/// 
/// 
/// 
/// 
/// 
/// 
/////////////////////////////////////////////////////
#pragma once

//Include My Code

//Include Other

//Defines

//Const

//Prototypes

//Class Prototypes
class Texture;

//Class Declaration

//Namespaces

namespace Textures
{
	enum ID
	{
		Angrosh,
		BigOverlays,
		Cellia,
		Cellia_Armor,
		Cellia_Armor_FaceHelm,
		Cellia_Armor_FaceHelm_Helm,
		Cellia_Armor_Helm,
		Cellia_Bandana_FaceHelm2_Fighter,
		Cellia_Boucle,
		Cellia_Boucle_Cape3,
		Cellia_Boucle_Cape3_Mage,
		Cellia_Boucle_Mage,
		Cellia_Cape1,
		Cellia_Cape1_Goggles,
		Cellia_Cape1_Goggles_Scarf,
		Cellia_Cape1_Scarf,
		Cellia_Cape2,
		Cellia_Cape2_Goggles,
		Cellia_Cape2_Goggles_Scarf,
		Cellia_Cape2_Scarf,
		Cellia_Cape3,
		Cellia_Cape3_Mage,
		Cellia_Flowers,
		Cellia_Flowers_Robe,
		Cellia_Flowers_Robe_Wings,
		Cellia_Flowers_Wings,
		Cellia_Goggles,
		Cellia_Goggles_Scarf,
		Cellia_Hidden,
		Cellia_Hidden_Scarf,
		Cellia_Mage,
		Cellia_Naked,
		Cellia_Robe,
		Cellia_Robe_Wings,
		Cellia_Wings,
		Mob_Goblin,
		Mob_Orc,
		Mob_Zombie,
		Neydala,
		Neydala_Suit,
		Neydala_Fight,
		Neydala_Fight_Mask,
		Neydala_Naked,
		Neydala_Royal,
		Ray,
		Ray_Armor_FaceHelm,
		Ray_Armor_FaceHelm_Plate,
		Ray_Armor_Helm,
		Ray_Armor_Helm_Plate,
		Ray_Armor_Plate,
		Ray_Naked,
		Tex,
		Tileset,
		TilesetContour,
		TreeApple,
		TreeStd,
		TuxedoMan,
		Villager,
		TextureNumber
	};
}

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<Texture, Textures::ID> TextureHolder;
//typedef ResourceHolder<Font, Fonts::ID> FontHolder;
//typedef ResourceHolder<Shader, Shaders::ID> ShaderHolder;
//typedef ResourceHolder<SoundBuffer, SoundEffect::ID> SoundBufferHolder;