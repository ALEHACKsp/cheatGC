#pragma once

class KGCDropItem_MISSION;
class KGCDropItem_ITEM;
class KGCDropItem_GP;
class KGCDropItem;

class VTKGCDropItem_MISSION;
class VTKGCDropItem_ITEM;
class VTKGCDropItem_GP;
class VTKGCDropItem;

class KGCDropItem_MISSION : KGCDropItem_ITEM, KGCDropItem {

public:

	VTKGCDropItem_MISSION* VT_KGCDropItem_MISSION;

};

class VTKGCDropItem_MISSION {

public:

	char pad_0x0000[0x24];

};

//

class KGCDropItem_ITEM {

public:

	VTKGCDropItem_ITEM* VT_KGCDropItem_ITEM;

};

class VTKGCDropItem_ITEM {

public:

	char pad_0x0000[0x24];

};

//

class KGCDropItem_GP : KGCDropItem_ITEM, KGCDropItem {

public:

	VTKGCDropItem_GP* VT_KGCDropItem_GP;

};

class VTKGCDropItem_GP {

public:

	char pad_0x0000[0x24];

};

//

class KGCDropItem {

public:

	VTKGCDropItem * VT_KGCDropItem;

};

class VTKGCDropItem {

public:

	char pad_0x0000[0x24];

};