#ifndef _CMIDNIGHTX_H_INCLUDED_
#define _CMIDNIGHTX_H_INCLUDED_

#include "info.h"
#include "../baseinc/scenario.h"

#ifdef _MARMALADE_
#include "IwDebug.h"
#endif

#define ISARG(x)	chilli::lib::stricmp( arg, x ) == 0 
#define COMMAND(x)	static MXRESULT (x)( const string& arg, variant argv[], u32 argc)
#define random		randomno::instance.get
#define chance		randomno::instance.chance
#define EOS(x)		x+chilli::lib::strlen(x)


namespace tme {

	DECLARE_ENUM(arguments) {
		character	=	128+IDT_CHARACTER,
		stronghold	=	128+IDT_STRONGHOLD,
		routenode	=	128+IDT_ROUTENODE,
		regiment	=	128+IDT_REGIMENT,
		objectinfo	=	128+IDT_OBJECT,
		location	=	128+IDT_LOCATION,
		direction	=	128+IDT_DIRECTIONINFO,
		area		=	128+IDT_AREAINFO,
		terrain		=	128+IDT_TERRAININFO,
		string		=	128+IDT_STRING,
	END_ENUM(arguments);

	typedef struct mxcommand_t {
		LPCSTR		name;
		u32			argcount;
		PFNCOMMAND	pfnCommand;
		u32			arguments[16];
	} mxcommand_t;

		using namespace tme::collections;
		
	class mxengine  
	{
	public:
		mxengine();
		virtual ~mxengine();

		virtual MXRESULT SetDatabaseDirectory ( const string& directory ) ;
		virtual MXRESULT LoadDatabase ( void ) ;
		virtual MXRESULT UnloadDatabase ( void ) ;
		//virtual MXRESULT LoadDefaultScenario ( void ) ;
		virtual MXRESULT LoadScenario ( mxscenario* scenario ) ;
		virtual MXRESULT UnloadScenario () ;
		virtual MXRESULT SaveGame ( const string& filename, PFNSERIALIZE function ) ;
		virtual MXRESULT LoadGame ( const string& filename, PFNSERIALIZE function ) ;
        virtual MXRESULT SaveGameDescription ( const string& filename, string& description );

		virtual MXRESULT ProcessCommand ( mxcommand_t tblCommand[], u32 max, const string& arg, variant argv[], u32 argc )  ;

		virtual void NightCallback( callback_t* )  ;

		virtual LPSTR LastActionMsg() ;
		virtual void Error ( u32 errorcode )  ;
		virtual u32 Error () const   ;
		
        //
        MXRESULT LoadDiscoveryMap ( const string& filename );
        MXRESULT SaveDiscoveryMap ( const string& filename );
        
		void debug (LPCSTR format, ... );
        
		// tme::item
		mxroutenode*	RouteNodeById(u32 id) ;
		mxcharacter*	CharacterById(u32 id) ;
		mxstronghold*	StrongholdById(u32 id) ;
		mxregiment*		RegimentById(u32 id) ;
		mxplace*		PlaceById(u32 id) ;
		mxobject*		ObjectById(u32 id) ;
		mxvictory*		VictoryById(u32 id) ;
		mxmission*		MissionById(u32 id) ;

		// tme::info
		mxdirection*	DirectionById(u32 id) ;
		mxunitinfo*		UnitById(u32 id) ;
		mxrace*			RaceById(u32 id) ;
		mxgender*		GenderById(u32 id) ;
		mxterrain*		TerrainById(u32 id) ;
		mxarea*			AreaById(u32 id) ;
		mxcommand*		CommandById(u32 id) ;
#if defined(_DDR_)
        mxobjectpower*  ObjectPowerById(u32 id);
        mxobjecttype*   ObjectTypeById(u32 id);
#endif
		// current char
		void CurrentChar ( mxcharacter* character);
		mxcharacter* CurrentChar ( void ) const;
		
		u32 CollectRegiments ( mxgridref loc, entities& collection ) ;
		u32 CollectStrongholds ( mxgridref loc, entities& collection ) ;
		u32 CollectRoutenodes ( mxgridref loc, entities& collection ) ;

		cvarreg_t* FindDBVariable ( const string& name ) const;
		mxentity* EntityByName( const string& name, id_type_t type=IDT_NONE );
		mxentity* EntityByIdt( mxid id );
        LPCSTR EntitySymbolById ( mxid id );
		MXRESULT EntityLinkData( mxid id, const void* data );

        u32 SaveGameVersion() const { return savegameversion; }
        BOOL isSavedGame() const { return m_savegame; }
        BOOL isDatabase() const { return !isSavedGame(); }
        
        
	public:
		mxmap*					gamemap;
        mxdiscoverymap*         discoverymap;
		mxtext*					text;
		mxnight*				night;
		mxbattle*				battle;
		mxscenario*				scenario;
		
		entities				objCharacters;
		entities				objRegiments;
		entities				objRoutenodes;
		entities				objStrongholds;
		entities				objPlaces;
		entities				objMissions;
		entities				objVictories;
		entities				objObjects;
		infos					objDirectionInfos;
		infos					objUnitInfos;
		infos					objRaceInfos;
		infos					objGenderInfos;
		infos					objTerrainInfos;
		infos					objAreaInfos;
		infos					objCommandInfos;
#if defined(_DDR_)
        infos                   objObjectPowersInfos;
        infos                   objObjectTypesInfos;
#endif
		//types::randomno			m_random ;
		PFNNIGHTCALLBACK		pfnNightCallback ;

		BOOL					m_bEnergyCheat;
		u32						m_versionno;
		BOOL					m_savegame;


	private:
		cvarreg_t*				variables ;
	//os::config*				m_config;
		BOOL					defaultscenario;
		u32						m_errorcode;
		mxcharacter*			m_CurrentCharacter;
		char					m_szDatabase[MAX_PATH];			
		char					lastactiontext[1024];
        
        u32                     savegameversion;

	};

	inline LPSTR mxengine::LastActionMsg()
		{ return lastactiontext; }

	extern mxengine* mx;


}
// namespace tme


    
#ifdef IW_DEBUG
#define MX_DEBUG_ON 1
#define MXTRACE		mx->debug
#else
#define MXTRACE		if(0) printf
#endif
    
using namespace tme;


#endif //_CMIDNIGHTX_H_INCLUDED_
	
