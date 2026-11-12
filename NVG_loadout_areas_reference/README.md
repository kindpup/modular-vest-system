# NVG framework loadout areas – reference copy

Copied from `NVG/ACM night vision framework` on 2026-11-09 for reference only.
This folder is **outside** the `vest_test` addon, so Workbench never loads or compiles it.
No `.meta` files were copied, so no resource IDs are duplicated.

## How the NVG framework attaches gear

| Area type (class) | Defined in | Used by | What it is for |
|---|---|---|---|
| `ACM_NV_Slotted` | `Scripts/Game/NightVision/ACM_ItemSlot.c` | every NVG prefab (`BaseLoadoutClothComponent > AreaType`) | The **NVG itself**. A helmet or headstrap needs a slot of this type to hold goggles. |
| `ACM_Headstrap` | `ACM_ItemSlot.c` | `Character_Base.et` (character slot), `Tracer Tactical Headstrap.et`, `PVS5.et` | A head-worn strap that holds an NVG without a helmet. |
| `ACM_NV_ItemSlot` | `ACM_ItemSlot.c` | night vision / thermal "is it worn?" checks, inventory UI | An NVG worn directly in a character slot. |
| `ACM_RailLEFT` / `ACM_RailRight` | `Scripts/Game/UI/Inventory/ACM_LoadoutAreas_ACMNVAL.c` | `MPLS Left/Right.et`, `Surfire Left/Right.et` | Helmet side-rail lights. |
| `ACM_Strobe` | `ACM_LoadoutAreas_ACMNVAL.c` | `MS2000.et`, `Strobe IR.et` | Helmet strobe. |
| `ACM_Vlite` | `ACM_LoadoutAreas_ACMNVAL.c` | `Vlite.et` | V-Lite helmet light. |
| `ACM_NVG`, `ACM_ThermalOverlay` | `ACM_LoadoutAreas_ACMNVAL.c` | `InventoryUI.conf` (ThermalOverlay row) | Leftover / inventory-row only. |

Supporting scripts:

- `Scripts/Game/ACM_ItemTypes.c` – adds `ACM_Headstrap` to `ECommonItemType`.
- `Scripts/Game/ACM_InventoryOverride.c` – makes NVGs mounted on a helmet show up in the helmet's inventory panel (looks for `ACM_NV_Slotted` items in `LoadoutHeadCoverArea` / `ACM_NV_ItemSlot` storages).
- `Scripts/Game/ACM_InventoryUtils.c` – finds which character is carrying a mounted item (walks helmet → mount → device).
- `Scripts/Game/NightVision/ACM_CharacterCameraHandlerComponent.c` – hides the NVG / headstrap model in first person (fades `ACM_Headstrap`, `ACM_NV_Slotted`, `ACM_NV_ItemSlot`, and devices mounted on the helmet).
- `Configs/Inventory/InventoryUI.conf` – adds the "Headstrap" row to the inventory screen.

Helmet chain the night vision checks expect:

```
character -> helmet (head cover) -> NVG mount (storage slot of type ACM_NV_Slotted) -> NVG
character -> headstrap (ACM_Headstrap) -> NVG
```

## What this means for vest_test helmets

`vest_test` helmets (`ACM_SFHC.et`, `Apache_Helmet.et`, `ACM_Crye_AirFrame.et`) use their **own** slot types:

| vest_test helmet slot | NVG framework gear that should go there |
|---|---|
| `ACM_AVS_M_NVG_Mount` | NVGs (they use `ACM_NV_Slotted`) |
| `ACM_AVS_M_Light_Left` / `ACM_AVS_M_Light_right` | MPLS / Surefire (`ACM_RailLEFT` / `ACM_RailRight`) |
| `ACM_AVS_M_Strobe` | MS2000 / Strobe IR (`ACM_Strobe`) |

Because the types differ, the NVG framework's goggles and lights **do not fit** those helmet slots today.
Ways to connect them:

1. **Recommended:** add the NVG framework (GUID `6ACB4A72C8EBC56B`) as a dependency in `vest_test/addon.gproj`, then change the helmet slots' `AreaType` to `ACM_NV_Slotted`, `ACM_RailLEFT`, `ACM_RailRight`, `ACM_Strobe`. No code is duplicated.
2. Change the NVG framework's item prefabs to use the vest_test slot types (makes the NVG mod depend on vest_test instead).
3. Copy the classes into `vest_test/Scripts`. **Avoid**: anyone running both mods gets "class already defined" errors.

## Issues spotted in vest_test helmets

- `ACM_SFHC.et`: slot `ACM_AVS_M_BatteryPack_Jack` uses AreaType `AVS_M_BatteryPack_Jack`, which no script defines (missing `ACM_` prefix?).
- `ACM_SFHC.et`: slot `ACM_AVS_M_Patch_Left` uses AreaType `ACM_AVS_M_Light_Left` (looks like a copy-paste; `ACM_AVS_M_Patch_Left` was probably meant).
- `vest_test` defines `m_ACM_AdditionalCommonItemTypes` (in `ACM_ItemAttributeCollection.c`). The NVG framework's prefabs used that field, which errored when the NVG mod was loaded without vest_test; it was removed from the NVG prefabs on 2026-11-09.
- `vest_test` defines `ACM_Ghillie`; the NVG framework's `Character_Base.et` had a Ghillie slot using it (removed from the NVG mod on 2026-11-09).
