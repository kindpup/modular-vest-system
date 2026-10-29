//
//  ACM
//  ACM Loadout Areas — unified registry
//
//  Original ACM-owned script for the modular framework.
//==================================================================================================

/*!
	Single authoritative declaration point for every `LoadoutAreaType` owned by
	ACM Modular Framework.

	Consolidated from:
	  - Scripts/Game/Loadout/Loadoutareas.c
	  - Scripts/Game/ACM Loadouts Vest.c
	  - Scripts/Game/ACM Loadouts Waist.c
	  - Scripts/Game/ACM_Patch_Loadout.c

	Class names are UNCHANGED — prefabs referencing these areas keep working.
	Only the file layout and ordering changed.

	Layout rules:
	  - Sections are grouped by body region / carrier, top to bottom.
	  - Classes are sorted A-Z within each section.
	  - One declaration per line, `class X : LoadoutAreaType {};`

	Adding a new area:
	  1. Declare it in the matching section below (keep A-Z order).
	  2. Append a family value + mapping in `Loadout/Area Routing Types.c`,
	     otherwise the area resolves to `ACM_EAreaFamily.NONE` and is skipped
	     by family-equivalence queries.

	Related, deliberately NOT in this file:
	  - `ACM_GearMorphSlotInfo` (Scripts/Game/ACM Patch Morph Loadoutslot.c)
	    is a `LoadoutSlotInfo`, not an area type.
	  - Add-on mods (Helmets, OPFOR Helmets, Apparel, Backpacks, NV & Lights,
	    Vehicle Crew Helmets) declare their own areas in their own projects.
	    Do not move them here — it would make the framework depend on them.
*/

//------------------------------------------------------------------------------------------------
// CORE / SHARED
// Generic areas not bound to a single carrier.
//------------------------------------------------------------------------------------------------
class ACM_Accessory : LoadoutAreaType {};
class ACM_Carabiner : LoadoutAreaType {};
class ACM_Chemlights : LoadoutAreaType {};
class ACM_Large_Carabiner : LoadoutAreaType {};
class ACM_Small_Carabiner : LoadoutAreaType {};
class ACM_Small_Storage_Pouch : LoadoutAreaType {};

//------------------------------------------------------------------------------------------------
// HEAD & FACE
//------------------------------------------------------------------------------------------------
class ACM_Mask : LoadoutAreaType {};
class ACM_Eyewear : LoadoutAreaType {};
class ACM_Beard : LoadoutAreaType {};


//------------------------------------------------------------------------------------------------
// TORSO — APPAREL & PATCHES
//------------------------------------------------------------------------------------------------
class ACM_FlagPatch : LoadoutAreaType {};
class ACM_Ghillie : LoadoutAreaType {};
class ACM_ShirtPatch : LoadoutAreaType {};

//------------------------------------------------------------------------------------------------
// VEST — PANELS & PLACARDS
//------------------------------------------------------------------------------------------------
class ACM_Vest_Backpanel : LoadoutAreaType {};
class ACM_Vest_Mag_Placard : LoadoutAreaType {};
class ACM_Vest_Placard_Pouches : LoadoutAreaType {};
class ACM_Vest_Single_Pouches : LoadoutAreaType {};

//------------------------------------------------------------------------------------------------
// Belt/Vest fun stuff
//------------------------------------------------------------------------------------------------
class ACM_Fun_Stuff : LoadoutAreaType {};


//------------------------------------------------------------------------------------------------
// VEST — POUCHES & ACCESSORIES
//------------------------------------------------------------------------------------------------
class ACM_Front_Admin_Pouch : LoadoutAreaType {};
class ACM_Shoulder_Accessory : LoadoutAreaType {};
class ACM_Vest_Belly_Pouch : LoadoutAreaType {};
class ACM_Vest_Chest_Accessories : LoadoutAreaType {};
class ACM_Vest_Holster : LoadoutAreaType {};

//------------------------------------------------------------------------------------------------
// VEST — ARMOR PLATES
//------------------------------------------------------------------------------------------------
class ACM_Back_Plate : LoadoutAreaType {};
class ACM_Front_Plate : LoadoutAreaType {};
class ACM_Left_Plate : LoadoutAreaType {};
class ACM_Right_Plate : LoadoutAreaType {};

//------------------------------------------------------------------------------------------------
// VEST — COSMETIC
//------------------------------------------------------------------------------------------------
class ACM_Vest_JPC_Color : LoadoutAreaType {};

//------------------------------------------------------------------------------------------------
// COMMS & RADIO
//------------------------------------------------------------------------------------------------
class ACM_Long_Mic_Chord : LoadoutAreaType {};
class ACM_MPU5_Microphone : LoadoutAreaType {};
class ACM_Radio_antena : LoadoutAreaType {};
class ACM_Radio_Pouch : LoadoutAreaType {};

//------------------------------------------------------------------------------------------------
// BELT & WAIST
//------------------------------------------------------------------------------------------------
class ACM_Belt_Dump_Pouch : LoadoutAreaType {};
class ACM_Belt_Fanny_Pack : LoadoutAreaType {};
class ACM_Belt_Holster : LoadoutAreaType {};
class ACM_Belt_Holster_Strap : LoadoutAreaType {};
class ACM_Belt_Knife_Slot : LoadoutAreaType {};
class ACM_Belt_Mag_Pouch : LoadoutAreaType {};
class ACM_Belt_Nade_Slot : LoadoutAreaType {};
class ACM_Belt_Pistol_Mag_Pouch : LoadoutAreaType {};
class ACM_Belt_Rear_Pouch : LoadoutAreaType {};
class ACM_Belt_Tether_Slot : LoadoutAreaType {};
class ACM_BeltGunClip : LoadoutAreaType {};
class ACM_Double_AR_Pouch : LoadoutAreaType {};
class ACM_Waist : LoadoutAreaType {};

//------------------------------------------------------------------------------------------------
// LEGS
//------------------------------------------------------------------------------------------------
class ACM_L_Leg : LoadoutAreaType {};
class ACM_Leg_Pouch : LoadoutAreaType {};
class ACM_R_Leg : LoadoutAreaType {};
class ACM_TQ_2 : LoadoutAreaType {};

//------------------------------------------------------------------------------------------------
// BACKPACK & BAG
//------------------------------------------------------------------------------------------------
class ACM_Bag_Pouch_Setup : LoadoutAreaType {};
class ACM_Bag_SlotArea_Bottom : LoadoutAreaType {};
class ACM_Bag_SlotArea_Left : LoadoutAreaType {};
class ACM_Bag_SlotArea_Right : LoadoutAreaType {};

//------------------------------------------------------------------------------------------------
// WEAPON CARRIAGE
//------------------------------------------------------------------------------------------------
class ACM_Sling : LoadoutAreaType {};

