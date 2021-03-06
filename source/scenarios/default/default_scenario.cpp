/*
 * FILE:    default_scenario.cpp
 * 
 * PROJECT: MidnightEngine
 * 
 * CREATED: 
 * 
 * AUTHOR:  Chris Wild
 * 
 * Copyright 2011 Chilli Hugger. All rights reserved.
 * 
 * PURPOSE: 
 * 
 * 
 */

#include "../../baseinc/tme_internal.h"

using namespace chilli;
using namespace chilli::lib;
using namespace chilli::collections;

namespace tme {

#define CONVERT_COLLECTION(x,y) \
	c_mxid& y = (c_mxid&) *((c_mxid*)x.vPtr)

#define CONVERT_GRIDREF(x,y) \
	mxgridref y = mxgridref( GET_LOCIDX((mxid)x),GET_LOCIDY((mxid)x) );

	//namespace scenarios {

    scenarioinfo_t	scenario_info = {
        1,
        100,
        "Default Scenario",
        "Chris Wild",
        "rorthron@thelordsofmidnight.com",
        "http://www.thelordsofmidnight.com",
        "Default scenario for the Midnight Engine",
        "Copyright 1999 - 2016 Mike Singleton & Chris Wild"
    };

	mxscenario* def_scenario = NULL ;

	
	MXRESULT MXAPI default_scenario::Create ( mxinterface* engine )
	{
		variant args;
		
		if ( engine == NULL )
			return MX_FAILED ;
		
		def_scenario = new mxscenario ;
		
		if ( def_scenario == NULL )
			return MX_FAILED ;
		
		args = def_scenario ;
		return engine->Command("@SETSCENARIO", &args, 1);
		
	}
			
	scenarioinfo_t* default_scenario::GetInfoBlock() const
	{
		return def_scenario->GetInfoBlock();
	}
	
	
	MXRESULT default_scenario::Register ( mxengine* midnightx )
	{
		return def_scenario->Register(midnightx);
	}
	
	MXRESULT default_scenario::UnRegister ( mxengine* midnightx )
	{
		return def_scenario->UnRegister(midnightx);
	}
	
	MXRESULT default_scenario::Command ( const string& arg, variant argv[], u32 argc )
	{
		return def_scenario->Command(arg, argv, argc);
	}
	
	MXRESULT default_scenario::GetProperties ( const string& arg, variant argv[], u32 argc )
	{
		return def_scenario->GetProperties(arg, argv, argc);
	}
	
	MXRESULT default_scenario::Text ( const string& command, variant* argv, u32 args )
	{
		return def_scenario->Text(command, argv, args);
	}
	
	
	
	
	
	
	
	
	
	
		MXRESULT mxscenario::Register ( mxengine* midnightx )
		{
			// mx = midnightx ;
			// add in the interfaces
			mx->text = new mxtext;
			mx->night = new mxnight;
			mx->battle = new mxbattle;
			mx->scenario = this;
			return MX_OK ;
		}

		MXRESULT mxscenario::UnRegister ( mxengine* midnightx )
		{
			SAFEDELETE ( mx->text ) ;
			SAFEDELETE ( mx->night ) ;
			SAFEDELETE ( mx->battle ) ;
			//mx->scenario = this;
			//default_scenario=NULL ;
			return MX_OK ;
		}
		 
	
	
		mxscenario::mxscenario()
		{
		}

		mxscenario::~mxscenario()
		{
		}

		/*
		* Function name	: base::GetInfoBlock
		* 
		* Return type		: scenarioinfo_t*
		* 
		* Arguments		: 
		* 
		* Description	    : 
		* 
		*/

		scenarioinfo_t* mxscenario::GetInfoBlock() const
		{
			return &scenario_info ;
		}

		/*
		* Function name	: base::CreateItemClass
		* 
		* Return type		: object*
		* 
		* Arguments		: itemtype_t type
		* 
		* Description	    : 
		* 
		*/

		mxentity* mxscenario::CreateEntity ( id_type_t type )
		{
			switch ( type ) {
				case IDT_ARMY:
					return (mxentity*)new mxarmy ;
				case IDT_CHARACTER:
					return (mxentity*)new mxcharacter ;
				case IDT_LOCATIONINFO:
					return (mxentity*)new mxlocinfo ;
				case IDT_REGIMENT:
					return (mxentity*)new mxregiment ;
				case IDT_ROUTENODE:
					return (mxentity*)new mxroutenode ;
				case IDT_STRONGHOLD:
					return (mxentity*)new mxstronghold ;
				case IDT_PLACE:
					return (mxentity*)new mxplace ;
				case IDT_OBJECT:
					return (mxentity*)new mxobject ;
				case IDT_VICTORY:
					return (mxentity*)new mxvictory ;
				case IDT_MISSION:
					return (mxentity*)new mxmission ;

				case IDT_DIRECTIONINFO:
					return (mxentity*)new mxdirection ;
				case IDT_UNITINFO:
					return (mxentity*)new mxunitinfo ;
				case IDT_RACEINFO:
					return (mxentity*)new mxrace ;
				case IDT_GENDERINFO:
					return (mxentity*)new mxgender ;
				case IDT_TERRAININFO:
					return (mxentity*)new mxterrain ;
				case IDT_AREAINFO:
					return (mxentity*)new mxarea ;
				case IDT_COMMANDINFO:
					return (mxentity*)new mxcommand ;
#if defined(_DDR_)
				case IDT_OBJECT_POWER:
					return (mxentity*)new mxobjectpower ;
				case IDT_OBJECT_TYPE:
					return (mxentity*)new mxobjecttype ;
#endif
            }
			return NULL;
		}

		void mxscenario::NightStart(void)
		{
		}

		void mxscenario::NightStop(void)
		{
		}

		/*
		* Function name	: base::Serialize
		* 
		* Return type		: void
		* 
		* Arguments		: archive& ar
		* 
		* Description	    : 
		* 
		*/

		void mxscenario::Serialize ( archive& ar )
		{
		}

		/*
		* Function name	: base::CalcFearAdjuster
		* 
		* Return type		: void
		* 
		* Arguments		: mxCLocInfo* info
		* 
		* Description	    : 
		* 
		*/

		u32 mxscenario::CalcFearAdjuster(mxlocinfo* locinfo) const
		{
			return 0 ;
		}

		/*
		* Function name	: base::Calitem::strongholdAdjuster
		* 
		* Return type		: int
		* 
		* Arguments		: mxCLocInfo* locinfo
		* 
		* Description	    : 
		* 
		*/

		u32 mxscenario::CalcStrongholdAdjuster(void) const
		{
		int ii;
		u32 adj_stronghold;
		int count;

			adj_stronghold = 0;
			count=0;
			for (ii = 0; ii < sv_strongholds; ii++) {
				mxstronghold* stronghold =  mx->StrongholdById(ii+1);
				if ( stronghold->HasFallen() ) {
					adj_stronghold += stronghold->Influence() ;
					count++;
				}
			}
			return adj_stronghold ;
		}


        void mxscenario::GetCharacterFollowers ( mxcharacter* leader, collections::entities& collection )
        {
            collection.Clear();
			for ( int ii=0; ii<sv_characters; ii++ ) {
				mxcharacter* character = mx->CharacterById(ii+1);
				if ( character->following == leader )
					collection.Add(character) ;
			}
            
        }
    
		void mxscenario::GetDefaultCharacters ( collections::entities& collection )
		{
			collection.Clear();
			for ( u32 ii=0; ii<sv_character_default.Count(); ii++ )
				collection += mx->EntityByIdt(sv_character_default[ii]);
		}

		BOOL mxscenario::CanWeSelectCharacter ( const mxcharacter* character )
		{
			// TODO shouldn't we be checking if they are recruited here?
			if ( IsFeature(SF_MOONRING) ) {
				//mxobject* moonring = (mxobject*)mx->EntityByName("OB_MOONRING");
				//if ( moonring == NULL ) return TRUE ;
				//const mxcharacter* moonringcarrier = WhoHasObject(moonring);
				
                const mxcharacter* moonringcarrier = CurrentMoonringWearer();
                if ( moonringcarrier==NULL && !character->IsAllowedMoonring() )
					return FALSE;
			}
			return TRUE ;
		}
    

    

		static s32 modes[4][2] = {
			{  1,  1 },
			{ -1,  1 },
			{  1, -1 },
			{ -1, -1 },
		};

		static s32 adjust[21][2] = {

			{ -2, -4 }, // 1
			{ -1, -4 }, // 2
			{  0, -4 }, // 3

			{ -3, -3 }, // 4
			{ -2, -3 }, // 5
			{ -1, -3 }, // 6
			{  0, -3 }, // 7

			{ -4, -2 }, // 8
			{ -3, -2 }, // 9
			{ -2, -2 }, // 10
			{ -1, -2 }, // 11
			{  0, -2 }, // 12

			{ -4, -1 }, // 13
			{ -3, -1 }, // 14
			{ -2, -1 }, // 15
			{ -1, -1 }, // 16
			{  0, -1 }, // 17

			{ -4,  0 }, // 18
			{ -3,  0 }, // 19
			{ -2,  0 }, // 20
			{ -1,  0 }, // 21
		};

		static u32 steps[21][6] = {
			{ 17, 16, 12, 11,  6,  5 },	// 1
			{ 17, 12, 11,  7,  6,  0 },	// 2
			{ 17, 12,  7,  0,  0,  0 },	// 3
			{ 16, 10,  0,  0,  0,  0 },	// 4
			{ 17, 16, 11, 10,  0,  0 },	// 5
			{ 17, 16, 12, 11,  0,  0 },	// 6
			{ 17, 12,  0,  0,  0,  0 },	// 7
			{ 21, 16, 15, 14,  9,  0 },	// 8
			{ 21, 16, 15, 10,  0,  0 },	// 9
			{ 16,  0,  0,  0,  0,  0 },	// 10
			{ 16, 17,  0,  0,  0,  0 },	// 11
			{ 17,  0,  0,  0,  0,  0 },	// 12
			{ 21, 16, 20, 15, 14,  0 },	// 13
			{ 21, 16, 20, 15,  0,  0 },	// 14
			{ 21, 16,  0,  0,  0,  0 },	// 15
			{  0,  0,  0,  0,  0,  0 },	// 16
			{  0,  0,  0,  0,  0,  0 },	// 17
			{ 21, 20, 19,  0,  0,  0 }, // 18
			{ 21, 20,  0,  0,  0,  0 },	// 19
			{ 21,  0,  0,  0,  0,  0 },	// 20
			{  0,  0,  0,  0,  0,  0 },	// 21
		};

		static u32 affect[21][6] = {
			{  2,  2,  2,  2,  2,  3 },	// 1
			{  2,  2,  3,  3,  3,  0 },	// 2
			{  1,  1,  1,  0,  0,  0 },	// 3
			{  1,  1,  0,  0,  0,  0 },	// 4
			{  3,  2,  2,  3,  0,  0 },	// 5
			{  2,  2,  3,  3,  0,  0 },	// 6
			{  1,  1,  0,  0,  0,  0 },	// 7
			{  3,  2,  3,  3,  3,  0 },	// 8
			{  3,  2,  2,  3,  0,  0 },	// 9
			{  1,  0,  0,  0,  0,  0 },	// 10
			{  2,  2,  0,  0,  0,  0 },	// 11
			{  1,  0,  0,  0,  0,  0 },	// 12
			{  2,  3,  2,  3,  3,  0 },	// 13
			{  2,  2,  2,  2,  0,  0 },	// 14
			{  2,  2,  0,  0,  0,  0 },	// 15
			{  0,  0,  0,  0,  0,  0 },	// 16
			{  0,  0,  0,  0,  0,  0 },	// 17
			{  1,  1,  1,  0,  0,  0 }, // 18
			{  1,  1,  0,  0,  0,  0 },	// 19
			{  1,  0,  0,  0,  0,  0 },	// 20
			{  0,  0,  0,  0,  0,  0 },	// 21
		};


		void mxscenario::MakeMapAreaVisible ( mxgridref l, mxcharacter* character )
		{
		mxgridref dst;
		mxgridref newdst;
		mxterrain*	tinfo;

			mxloc& current = mx->gamemap->GetAt( l );
            
#if defined(_DDR_)
            // in a tunnel?
            if ( character->IsInTunnel() ) {
                current.flags|=lf_tunnel_looked_at|lf_tunnel_visited;
                
                // check the surrounding locations for tunnels
                // N E S W
                // and mark them as seen
                for ( int ii=DR_NORTH; ii<=DR_NORTHWEST; ii+=2 ) {
                    if ( mx->gamemap->IsTunnel(l + (mxdir_t)ii))
                        mx->gamemap->SetTunnelVisible(l + (mxdir_t)ii, true);
                }

                
                
                return;
            }
#endif
			
            mx->gamemap->SetLocationVisible(l, true);
            
			character->CanSeeLocation( l );

			for ( u32 i=0; i<NUMELE(modes); i++ ) {
				
				int dx = modes[i][0];
				int dy = modes[i][1];

				for ( u32 j=0; j<NUMELE(steps); j++ ) {

					int blocking=0;

					dst.x = l.x + ( adjust[j][0] * dx ) ;
					dst.y = l.y + ( adjust[j][1] * dy ) ;

					if ( !mx->gamemap->IsLocOnMap(dst) ) 
						continue;

					mxloc& lookingat = mx->gamemap->GetAt( dst );

					tinfo = mx->TerrainById(lookingat.terrain);
					int visibility = tinfo->Visibility();

                    
                    
					u32 k=0;
					for ( k=0; k<NUMELE(steps[0]); k++ ) {
					
						int d = steps[j][k] ;
						if ( d == 0 )
							break;

						newdst.x = l.x + ( adjust[d-1][0] * dx ) ;
						newdst.y = l.y + ( adjust[d-1][1] * dy ) ;

						if ( mx->gamemap->IsLocOnMap(newdst) )  {
						mxloc& current = mx->gamemap->GetAt( newdst );
							mxterrain* tinfo = mx->TerrainById(current.terrain);
							blocking += tinfo->Obstruction()/affect[j][k];
                            if ( blocking>=visibility ) break;
						}

					}

					if ( blocking<visibility ) {
						lookingat.flags|=lf_seen;
                        mx->gamemap->CheckVisibleRange(dst);
						// k==0 when the location dst - is adjacent to loc
						// at that point you will be able to see the army
						if ( k==0 || tinfo->IsArmyVisible() )
							character->CanSeeLocation( dst );
                        
					}
				}


			}


		}

		COMMAND( OnCharLookLeft ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			argv[0]=(s32)0;
			return character->Cmd_LookLeft();
		}

		COMMAND( OnCharLookRight ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			argv[0]=(s32)0;
			return character->Cmd_LookRight();
		}

		COMMAND( OnCharLook ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			argv[0]=(s32)0;
			return character->Cmd_LookDir( (mxdir_t) GET_ID( argv[1].vId ) );
		}

		COMMAND( OnCharForward ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			argv[0]=(s32)0;
			return character->Cmd_MoveForward();
		}

		COMMAND( OnCharPostMen ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			CONVERT_STRONGHOLD_ID( argv[1].vId, stronghold );
			argv[0]=(s32)0;
			return character->Cmd_PostMen( stronghold, 0 );
		}

		COMMAND( OnCharRecruitMen ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			CONVERT_STRONGHOLD_ID( argv[1].vId, stronghold );
			argv[0]=(s32)0;
			return character->Cmd_RecruitMen( stronghold, 0 );
		}

		COMMAND( OnCharAttack ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			argv[0]=(s32)0;
			return character->Cmd_Attack();
		}

		COMMAND( OnCharRest ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			argv[0]=(s32)0;
			return character->Cmd_Rest();
		}

		COMMAND( OnCharHide ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			argv[0]=(s32)0;
			return character->Cmd_Hide();
		}

		COMMAND( OnCharUnHide ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			argv[0]=(s32)0;
			return character->Cmd_UnHide();
		}

		COMMAND( OnCharLookAt ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			CONVERT_GRIDREF(argv[1],loc);
			argv[0]=(s32)0;
			return character->Cmd_Lookat(loc);
		}

		COMMAND( OnCharApproach ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			CONVERT_CHARACTER_ID( argv[1].vId, recruit );
			mxcharacter* recruited = character->Cmd_Approach(recruit);
			if ( recruited ) {
				argv[1] = recruited->SafeIdt();
				argv[0] = (s32)1;
				return MX_OK ;
			}
			argv[0]=(s32)0;
			return MX_FAILED ;
		}

        COMMAND( OnCharFollow ) 
        {
            CONVERT_CHARACTER_ID( argv[0].vId, character );
            CONVERT_CHARACTER_ID( argv[1].vId, c );

            if ( character->Cmd_Follow(c) ) {
                argv[0] = (s32)0;
                return MX_OK ;
            }
            argv[0]=(s32)0;
            return MX_FAILED ;
        }

        COMMAND( OnCharDisbandGroup )
        {
            CONVERT_CHARACTER_ID( argv[0].vId, character );
            argv[0]=(s32)0;
            return character->Cmd_DisbandGroup();
        }
        
        COMMAND( OnCharSwapGroupLeader )
        {
            CONVERT_CHARACTER_ID( argv[0].vId, character );
            CONVERT_CHARACTER_ID( argv[1].vId, c );
            argv[0]=(s32)0;
            return character->Cmd_SwapGroupLeader(c);
        }
    
        COMMAND( OnCharUnFollow )
        {
            CONVERT_CHARACTER_ID( argv[0].vId, character );
            CONVERT_CHARACTER_ID( argv[1].vId, c );
            
            if ( character->Cmd_UnFollow(c) ) {
                argv[0] = (s32)0;
                return MX_OK ;
            }
            argv[0]=(s32)0;
            return MX_FAILED ;
        }
    
		COMMAND( OnCharFight ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			mxobject* object = character->Cmd_Fight();
			if ( object != NULL ) {
				argv[1] = object->SafeIdt();
				argv[0] = (s32)1;
				return MX_OK ;
			}
			argv[0]=(s32)0;
			return MX_FAILED ;
		}

		COMMAND( OnCharSeek ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			mxobject* object = character->Cmd_Seek();
			if ( object != NULL ) {
				argv[1] = object->SafeIdt();
				argv[0] = (s32)1;
				return MX_OK ;
			}
			argv[0]=(s32)0;
			return MX_FAILED ;
		}

		COMMAND( OnCharPickup ) 
		{
			argc=0;
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			// TODO Check return Type
			mxobject* object  = character->Cmd_PickupObject();
			if ( object != NULL ) {
				argv[1] = object->SafeIdt();
				argv[0] = (s32)1;
				return MX_OK ;
			}
			argv[0]=(s32)0;
			return MX_FAILED ;
		}

		COMMAND( OnCharDrop ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			argv[0]=(s32)0;
			return character->Cmd_DropObject();
		}

		COMMAND( OnCharWait ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			argv[0]=(s32)0;
			return character->Cmd_Wait((mxwait_t)argv[1].vInt);
		}

		COMMAND( OnCharControl ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			argv[0]=(s32)0;
			mx->CurrentChar(character);
			return MX_OK;
		}

#if defined(_DDR_)
		COMMAND( OnCharEnterTunnel ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			argv[0]=(s32)0;
			return character->Cmd_EnterTunnel();
		}

		COMMAND( OnCharExitTunnel ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			argv[0]=(s32)0;
			return character->Cmd_ExitTunnel();
		}

        COMMAND( OnCharGive )
        {
            CONVERT_CHARACTER_ID( argv[0].vId, character );
            CONVERT_CHARACTER_ID( argv[1].vId, to );
            argv[0]=(s32)0;
            return character->Cmd_Give(to);
        }

        COMMAND( OnCharTake )
        {
            CONVERT_CHARACTER_ID( argv[0].vId, character );
            argv[0]=(s32)0;
            return character->Cmd_Take();
        }

        COMMAND( OnCharUse )
        {
            CONVERT_CHARACTER_ID( argv[0].vId, character );
            argv[0]=(s32)0;
            return character->Cmd_Use();
        }

#endif
    
		COMMAND( OnRegimentHold )
		{
			CONVERT_REGIMENT_ID( argv[0].vId, regiment );
			regiment->Orders( OD_HOLD );
			regiment->TargetId( 0 );
			argv[0]=(s32)0;
			return MX_OK ;
		}

		COMMAND( OnRegimentGoto )
		{
			CONVERT_REGIMENT_ID( argv[0].vId, regiment );
			CONVERT_ENTITY_ID( argv[1].vId, dst );
			regiment->Orders( OD_GOTO );
			regiment->TargetId( dst->SafeIdt() );
			argv[0]=(s32)0;
			return MX_OK ;
		}

		COMMAND( OnRegimentWander )
		{
			CONVERT_REGIMENT_ID( argv[0].vId, regiment );
			regiment->Orders( OD_WANDER );
			argv[0]=(s32)0;
			return MX_OK ;
		}

		COMMAND( OnRegimentFollow )
		{
			CONVERT_REGIMENT_ID( argv[0].vId, regiment );
			CONVERT_ENTITY_ID( argv[1].vId, dst );
			regiment->Orders( OD_FOLLOW );
			regiment->TargetId( dst->SafeIdt() );
			argv[0]=(s32)0;
			return MX_OK ;
		}

		COMMAND( OnRegimentRoute )
		{
			CONVERT_REGIMENT_ID( argv[0].vId, regiment );
			CONVERT_ENTITY_ID( argv[1].vId, dst );
			regiment->Orders( OD_ROUTE );
			regiment->TargetId( dst->SafeIdt() );
			argv[0]=(s32)0;
			return MX_OK ;
		}


		COMMAND ( OnNight )
		{

			mx->pfnNightCallback = (PFNNIGHTCALLBACK)argv[0].vPtr ;

			argv[0]=(s32)0;

#if defined(_DDR_)
            sv_days++;
            mx->LastActionMsg()[0] = '\0';
#endif
            
#ifdef _TEST_WINLOSE_CONDITIONS_
            mx->night->testWinLoseConditions();
#endif

            m_gameover_t win = mx->night->CheckWinLoseConditions(TRUE);
            if ( win != MG_NONE ) {
                gameover_callback_t event;
                event.type = callback_t::gameover ;
                event.condition = win ;
                mx->NightCallback(&event);
                mx->text->PurgeCache();
                argv[1] = (s32)FALSE;
                return MX_OK ;
            }
            
#if defined(_LOM_)
            sv_days++;
            mx->LastActionMsg()[0] = '\0';
#endif
            mx->scenario->DeadCharactersDropObjects();

			chilli::lib::strcat ( mx->LastActionMsg(), mx->text->CookedSystemString(SS_NIGHT) );
			
			mx->NightCallback(NULL);

			mx->scenario->RemoveMapArmies();
			
			sv_strongholdadjuster = mx->scenario->CalcStrongholdAdjuster();
			
			mx->night->Process();

			mx->scenario->SetMapArmies();

			mx->scenario->SetCharsLooking();

            chilli::lib::strcat ( mx->LastActionMsg(), mx->text->CookedSystemString(SS_DAWN) );
            
			mx->text->PurgeCache();

			argv[1] = (s32)FALSE;

			return MX_OK ;

		}

    
        COMMAND( OnWinLose ) 
        {
            mx->LastActionMsg()[0] = '\0';
            
            m_gameover_t win = mx->night->CheckWinLoseConditions(FALSE);
            
			mx->text->PurgeCache();
            
			argv[1] = (u32)win;
            
			return MX_OK ;
            
        }
    

		COMMAND( OnGetPanoramic ) 
		{
			// location
			CONVERT_GRIDREF(argv[0],loc);

			// direction
			mxdir_t dir = (mxdir_t)GET_ID(argv[1].vId) ;

			panloc_t* locations;

			int count = mx->gamemap->GetPanoramic ( loc, dir, &locations );

			argv[0] = (s32)count;
			argv[1] = locations ;

			
			return MX_OK ;
		}

		static mxcommand_t mx_commands[] = {
			
			// character commands} },
			{"LOOKLEFT",	1, OnCharLookLeft,		{arguments::character} },
			{"LOOKRIGHT",	1, OnCharLookRight, 	{arguments::character} },
			{"LOOK",		2, OnCharLook,			{arguments::character, arguments::direction} },
			{"FORWARD",		1, OnCharForward,		{arguments::character} },
			{"POSTMEN",		3, OnCharPostMen,		{arguments::character, arguments::stronghold, variant::vnumber} },
			{"RECRUITMEN",	3, OnCharRecruitMen,	{arguments::character, arguments::stronghold, variant::vnumber} },
			{"ATTACK",		1, OnCharAttack,		{arguments::character} },
			{"REST",		1, OnCharRest,			{arguments::character} },
			{"HIDE",		1, OnCharHide,			{arguments::character} },
			{"UNHIDE",		1, OnCharUnHide,		{arguments::character} },
			{"LOOKAT",		2, OnCharLookAt,		{arguments::character, arguments::location} },
			{"APPROACH",	2, OnCharApproach,		{arguments::character, arguments::character} },
			{"FIGHT",		1, OnCharFight,			{arguments::character} },
			{"SEEK",		1, OnCharSeek,			{arguments::character} },
			{"PICKUP",		1, OnCharPickup,		{arguments::character} },
			{"DROP",		1, OnCharDrop,			{arguments::character} },// arguments::objectinfo} },
			{"WAIT",		2, OnCharWait,			{arguments::character, variant::vnumber} }, //[mode]
			{"CONTROL",		1, OnCharControl,		{arguments::character} },
#if defined(_DDR_)
			{"ENTERTUNNEL",	1, OnCharEnterTunnel,	{arguments::character} },
			{"EXITTUNNEL",	1, OnCharExitTunnel,	{arguments::character} },
			{"GIVE",		1, OnCharGive,			{arguments::character} },
			{"TAKE",		1, OnCharTake,			{arguments::character} },
			{"USE",         1, OnCharUse,			{arguments::character, arguments::character} },
#endif
            {"FOLLOW",      2, OnCharFollow,        {arguments::character, arguments::character} },
            {"UNFOLLOW",    2, OnCharUnFollow,      {arguments::character, arguments::character} },
            {"DISBANDGROUP",1, OnCharDisbandGroup,  {arguments::character} },
            {"SWAPGROUPLEADER", 2, OnCharSwapGroupLeader,{arguments::character, arguments::character} },

            
					// Regiment Commands
			{"HOLD",		1, OnRegimentHold,		{arguments::regiment} },
			{"GOTO",		2, OnRegimentGoto,		{arguments::regiment, arguments::location} },
			{"WANDER",		1, OnRegimentWander,	{arguments::regiment} },
			{"FOLLOW",		2, OnRegimentFollow,	{arguments::regiment, arguments::character} },
			{"ROUTE",		2, OnRegimentRoute,		{arguments::regiment, arguments::routenode} },

					// other
			{ "NIGHT",		1, OnNight,				{variant::vptr} },
            { "CHECKWINLOSE", 0, OnWinLose },

			{ "GetPanoramic",	2,	OnGetPanoramic,	{arguments::location, arguments::direction}},


		};

		MXRESULT mxscenario::Command ( const string& arg, variant argv[], u32 argc )
		{
			return mx->ProcessCommand ( mx_commands, NUMELE(mx_commands), arg, argv, argc );
		}

		
		COMMAND ( PropCurrentCharacter )
		{
			argv[0]=(s32)1;
			argv[1]=mx->CurrentChar()->Id();
			return MX_OK ;
		}

		COMMAND( PropDefaultCharacters )
		{
			CONVERT_COLLECTION(argv[0],collection);
			//if ( ISARG("DEFAULTCHARACTERS") ) {
				collections::entities mycollection;
				mx->scenario->GetDefaultCharacters ( mycollection );
				if ( mycollection.CreateIdtCollection(collection) )
					return MX_OK ;
				return MX_FAILED ;
			//}
		}

		COMMAND ( PropCharacters )
		{
			CONVERT_COLLECTION(argv[0],collection);
			//if ( ISARG("CHARACTERS") ) {
				//if ( mx->objCharacters.CreateIdtCollection(collection) )
				//	return MX_OK ;
				//return MX_FAILED ;
			//}
            
            // don't return DOOMDARK
            // TODO: Create a flag for this!!!!
            mxcharacter* doomdark = (mxcharacter*)mx->EntityByName("CH_DOOMDARK");
            
            
            //collection.Create( mx->objCharacters.Count() );
			collection.Clear();
            for ( u32 ii=0; ii<mx->objCharacters.Count(); ii++ ) {
                mxcharacter* c = (mxcharacter*)mx->objCharacters[ii] ;
                if ( c!=doomdark )
                    collection.Add(c->SafeIdt());
            }
            return MX_OK ;
            
		}

		COMMAND ( PropRegiments )
		{
			CONVERT_COLLECTION(argv[0],collection);
			//if ( ISARG("REGIMENTS") ) {
				if ( mx->objRegiments.CreateIdtCollection(collection) )
					return MX_OK ;
				return MX_FAILED ;
			//}
		}

		COMMAND ( PropRouteNodes )
		{
			CONVERT_COLLECTION(argv[0],collection);
			//if ( ISARG("ROUTENODES") ) {
				if ( mx->objRoutenodes.CreateIdtCollection(collection) )
					return MX_OK ;
				return MX_FAILED ;
			//}
		}

		COMMAND ( PropPlaces )
		{
			CONVERT_COLLECTION(argv[0],collection);
			//if ( ISARG("ROUTENODES") ) {
				if ( mx->objPlaces.CreateIdtCollection(collection) )
					return MX_OK ;
				return MX_FAILED ;
			//}
		}

		COMMAND ( PropStrongholds )
		{
			CONVERT_COLLECTION(argv[0],collection);
			//if ( ISARG("STRONGHOLDS") ) {
			if ( mx->objStrongholds.CreateIdtCollection(collection) )
				return MX_OK ;
			return MX_FAILED ;
			//}
		}

		COMMAND ( PropCharacters2 )
		{
			CONVERT_COLLECTION(argv[0],collection);
			
			mxlocinfo* locinfo;
			if ( mx->scenario->GetLocInfo ( argv[1], locinfo ) != MX_OK )
				return MX_FAILED ;
            
			//if ( ISARG("CHARACTERS") ) {
			locinfo->objCharacters.CreateIdtCollection(collection);
			argv[1] = locinfo->nRecruited ;
			SAFEDELETE ( locinfo );
			return MX_OK ;
			//}
		}

		COMMAND ( PropRecruitable )
		{
			CONVERT_COLLECTION(argv[0],collection);
			mxlocinfo* locinfo;
			if ( mx->scenario->GetLocInfo ( argv[1], locinfo ) != MX_OK )
				return MX_FAILED;
			//if ( ISARG("RECRUITABLE") ) {
			locinfo->objRecruit.CreateIdtCollection(collection);
			SAFEDELETE ( locinfo );
			return MX_OK ;
			//}
		}

		COMMAND ( PropArmies )
		{
			CONVERT_COLLECTION(argv[0],collection);
			mxlocinfo* locinfo;
			mx->scenario->GetLocInfo ( argv[1], locinfo );

			//if ( ISARG("ARMIES") ) {
			collection.Create( locinfo->nArmies );
			for ( u32 ii=0; ii<locinfo->nArmies; ii++ ) {
				mxarmy* army = &locinfo->armies[ii] ;
				int type = army->armytype == AT_CHARACTER ? (128|army->type) : army->armytype ;
				collection[ii] = MAKE_ARMYID(type,army->parent->SafeId() );
			}
			argv[0] = (s32)8 ;
			argv[1] = locinfo->foe.warriors ;
			argv[2] = locinfo->foe.riders ;
			argv[3] = locinfo->friends.warriors ;
			argv[4] = locinfo->friends.riders ;
			argv[5] = locinfo->doomdark.warriors ;
			argv[6] = locinfo->doomdark.riders ;
			argv[7] = locinfo->friends.armies;
			argv[8] = locinfo->foe.armies;


			SAFEDELETE ( locinfo );
			return MX_OK ;
			//}
		}

		COMMAND ( PropStrongholds2 )
		{
			CONVERT_COLLECTION(argv[0],collection);
			mxlocinfo* locinfo;
			mx->scenario->GetLocInfo ( argv[1], locinfo );
			//if ( ISARG("STRONGHOLDS") ) {
			locinfo->objStrongholds.CreateIdtCollection(collection);
			SAFEDELETE ( locinfo );
			return MX_OK ;
			//}
		}
		/*
		COMMAND ( PropRouteNodes2 )
		{
			CONVERT_COLLECTION(argv[0],collection);
			mxlocinfo* locinfo;
			mx->scenario->GetLocInfo ( argv[1], locinfo );
			//if ( ISARG("ROUTENODES") ) {
			locinfo->objRoutenodes.CreateIdtCollection(collection);
			SAFEDELETE ( locinfo );
			return MX_OK ;
			//}
		}
		 */
		COMMAND ( PropCharsForCommand )
		{
			CONVERT_COLLECTION(argv[0],collection);
			CONVERT_GRIDREF(argv[2],loc);
			
			collections::entities	chars;
			mx->scenario->GetCharactersAvailableForCommand ( argv[1], loc, chars );
			chars.CreateIdtCollection( collection );

			return MX_OK ;
			//}
		}

		COMMAND ( PropArmiesAtLocation )
		{
			CONVERT_GRIDREF(argv[0],loc);
			u32 enemies=0;
			u32 friends=0;
			mx->scenario->FindArmiesAtLocation ( loc, enemies, friends, argv[1] );
			argv[0]=(s32)2;
			argv[1]=enemies;
			argv[2]=friends;
			return MX_OK ;
		}

		COMMAND ( PropCharsAtLoc )
		{
			CONVERT_COLLECTION(argv[0],collection);
			CONVERT_GRIDREF(argv[1],loc);
			collections::entities	chars;
			mx->scenario->FindCharactersAtLocation ( loc, chars, argv[2] );
			chars.CreateIdtCollection( collection );
			return MX_OK ;
		}

		COMMAND ( PropMapSize )
		{
			argv[0]=(s32)2;
			argv[1]=mx->gamemap->Size().cx;
			argv[2]=mx->gamemap->Size().cy;
			return MX_OK ;
		}

        COMMAND ( PropMapInfo )
        {
            argv[0]=(s32)6;
            
            if ( mx->discoverymap != NULL ) {
                argv[1]=mx->discoverymap->Top().x;
                argv[2]=mx->discoverymap->Top().y;
                argv[3]=mx->discoverymap->Bottom().x;
                argv[4]=mx->discoverymap->Bottom().y;
            }else{
                argv[1]=mx->gamemap->Top().x;
                argv[2]=mx->gamemap->Top().y;
                argv[3]=mx->gamemap->Bottom().x;
                argv[4]=mx->gamemap->Bottom().y;
            }
            
            argv[5]=(s32)argv[3]-(s32)argv[1];
            argv[6]=(s32)argv[4]-(s32)argv[2];
            return MX_OK ;
        }
    
		static mxcommand_t mx_properties[] = {
			{ "CONTROLLED_CHARACTER", 	0, PropCurrentCharacter },

			{ "DEFAULTCHARACTERS",	1, PropDefaultCharacters,	{variant::vptr} },
			{ "CHARACTERS",			1, PropCharacters,			{variant::vptr} },
			{ "REGIMENTS",			1, PropRegiments,			{variant::vptr} },
			{ "ROUTENODES",			1, PropRouteNodes,			{variant::vptr} },
			{ "STRONGHOLDS",		1, PropStrongholds,			{variant::vptr} },
			{ "PLACES",				1, PropPlaces,				{variant::vptr} },
			{ "CHARACTERS",			2, PropCharacters2,			{variant::vptr, variant::vid} },
			{ "RECRUITABLE",		2, PropRecruitable,			{variant::vptr, variant::vid} },
			{ "ARMIES",				2, PropArmies,				{variant::vptr, variant::vid} },
			{ "STRONGHOLDS",		2, PropStrongholds2,		{variant::vptr, variant::vid} },
			{ "ROUTENODES",			2, PropRouteNodes,			{variant::vptr, variant::vid} },

			{ "CharsForCommand",	3, PropCharsForCommand,		{variant::vptr, variant::vnumber, arguments::location} },
			{ "ArmiesAtLocation",	2, PropArmiesAtLocation,	{arguments::location, variant::vnumber} },
			{ "CharsAtLoc",			3, PropCharsAtLoc,			{variant::vptr, arguments::location, variant::vnumber} },
			
			{ "MAPINFO",            0, PropMapInfo,             },
			{ "MAPSIZE",			0, PropMapSize,				},


		};

		MXRESULT mxscenario::GetProperties ( const string& arg, variant argv[], u32 argc )
		{
			return mx->ProcessCommand ( mx_properties, NUMELE(mx_properties), arg, argv, argc );
		}


		COMMAND ( OnTextNumberPart ) 
		{
			argv[1] = mx->text->DescribeNumberPart ( (s32)argv[0] )  ;
			argv[0] = (s32)1 ;
			return MX_OK;
		}
				
		COMMAND ( OnTextEnergy ) 
		{
			argv[1] = mx->text->DescribeEnergy ( argv[0] );
			argv[0] = (s32)1 ;
			return MX_OK;
		}
					
		COMMAND ( OnTextFear ) 
		{
			argv[1] = mx->text->DescribeFear ( argv[0] );
			argv[0] = (s32)1 ;
			return MX_OK;
		}
						
		COMMAND ( OnTextCourage ) 
		{
			argv[1] = mx->text->DescribeCourage ( argv[0] );
			argv[0] = (s32)1 ;
			return MX_OK;
		}
					
		COMMAND ( OnTextCharRecruitMen ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			CONVERT_STRONGHOLD_ID( argv[1].vId, stronghold );
			argv[0] = (s32)1 ;
			argv[1] = mx->text->DescribeCharacterRecruitMen ( character, stronghold, argv[2] )  ;
			return MX_OK;
		}
			
		COMMAND ( OnTextCharPostMen ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			CONVERT_STRONGHOLD_ID( argv[1].vId, stronghold );
			argv[0] = (s32)1 ;
			argv[1] = mx->text->DescribeCharacterPostMen ( character, stronghold, argv[2] )  ;
			return MX_OK;
		}
				
		COMMAND ( OnTextCharTime ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			argv[0] = (s32)1 ;
			argv[1] = mx->text->DescribeCharacterTime( character ) ;
			return MX_OK;
		}
					
		COMMAND ( OnTextCharEnergy ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			argv[0] = (s32)1 ;
			argv[1] = mx->text->DescribeCharacterEnergy ( character ) ;
			return MX_OK;
		}
				
		COMMAND ( OnTextCharCourage ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			argv[0] = (s32)1 ;
			argv[1] = mx->text->DescribeCharacterCourage ( character ) ;
			return MX_OK;
		}
				
		COMMAND ( OnTextCharFear ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			argv[0] = (s32)1 ;
			argv[1] = mx->text->DescribeCharacterFear ( character ) ;
			return MX_OK;
		}
					
		COMMAND ( OnTextCharObject ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			argv[0] = (s32)1 ;
			argv[1] = mx->text->DescribeCharacterObject ( character )  ;
			return MX_OK;
		}
				
		COMMAND ( OnTextCharDeath ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			argv[0] = (s32)1 ;
			argv[1] = mx->text->DescribeCharacterDeath ( character )  ;
			return MX_OK;
		}
					
		COMMAND ( OnTextCharBattle ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			argv[0] = (s32)1 ;
			argv[1] = mx->text->DescribeCharacterBattle ( character ) ;
			return MX_OK;
		}
				
		COMMAND ( OnTextCharArmy ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			argv[0] = (s32)1 ;
			argv[1] = mx->text->DescribeCharacterArmy ( character ) ;
			return MX_OK;
		}
					
		//COMMAND ( OnTextCharAttributes ) 
		//{
		//	CONVERT_CHARACTER_ID( argv[0].vIdt, character );
		//	argv[0] = 1 ;
		//	argv[1] = mx->text->DescribeCharacterAttributes ( character ) ;
		//	return MX_OK;
		//}
			
		//COMMAND ( OnTextCharFoe ) 
		//{
		//	CONVERT_CHARACTER_ID( argv[0].vIdt, character );
		//	argv[0] = 1 ;
		//	argv[1] = mx->text->DescribeCharacterFoe ( character ) ;
		//	return MX_OK;
		//}
		//			
		//COMMAND ( OnTextCharLiege ) 
		//{
		//	CONVERT_CHARACTER_ID( argv[0].vIdt, character );
		//	argv[0] = 1 ;
		//	argv[1] = mx->text->DescribeCharacterLiege ( character ) ;
		//	return MX_OK;
		//}
					
		COMMAND ( OnTextCharLocation ) 
		{
			CONVERT_CHARACTER_ID( argv[0].vId, character );
			mx->CurrentChar(character);
			argv[0] = (s32)1 ;
			argv[1] = mx->text->DescribeCharacterLocation( character ) ;
			return MX_OK;
		}
				
		COMMAND ( OnTextStronghold ) 
		{
			CONVERT_STRONGHOLD_ID( argv[0].vId, stronghold );
			argv[0] = (s32)1 ;
			argv[1] = mx->text->DescribeStronghold (stronghold) ;
			return MX_OK;
		}
		/*
		COMMAND ( OnTextArmyTotal ) 
		{
			argv[0] = (s32)1 ;
			//argv[1] = mx->text->
			return MX_FAILED;
		}
		*/
	
		COMMAND ( OnTextLocation ) 
		{
			mxgridref loc = mxgridref( GET_LOCIDX(argv[0].vId),GET_LOCIDY(argv[0].vId) );
			argv[1] = mx->text->DescribeLocation(loc) ;
			argv[0] = (s32)1 ;
			return MX_OK;
		}
					
		COMMAND ( OnTextArea ) 
		{
			argv[1] = mx->text->DescribeArea(GET_ID(argv[0].vId)) ;
			argv[0] = (s32)1 ;
			return MX_OK;
		}

		COMMAND ( OnTextObject ) 
		{
			CONVERT_OBJECT_ID(argv[0].vId,object);
			argv[1] = mx->text->DescribeObject(object) ;
			argv[0] = (s32)1 ;
			return MX_OK;
		}
						
		COMMAND ( OnTextTerrainPlural ) 
		{
			argv[1] = mx->text->DescribeTerrainPlural((mxterrain_t)GET_ID(argv[0].vId));
			argv[0] = (s32)1 ;
			return MX_OK;
		}
				
		COMMAND ( OnTextTerrain ) 
		{
			argv[1] = mx->text->DescribeTerrainSingularPlural((mxterrain_t)GET_ID(argv[0].vId));
			argv[0] = (s32)1 ;
			return MX_OK;
		}
					
		COMMAND ( OnTextNumber )
		{
			argv[1] = mx->text->DescribeNumber ( (s32)argv[0], (mxtext::ZERO_MODE)(s32)argv[1] )  ;
			argv[0] = (s32)1 ;
			return MX_OK;
		}

		COMMAND ( OnTextSpecialStrings )
		{
			CONVERT_CHARACTER_ID( argv[1].vId, character );
			argv[1] = mx->text->CookedSystemString(GET_ID(argv[0].vId), character );
			argv[0] = (s32)1 ;
			return MX_OK;
		}

		COMMAND ( OnTextPurge )
		{
			mx->text->PurgeCache(NULL);
			argv[0] = (s32)0 ;																	
			return MX_OK;
		}

		COMMAND ( OnLastActionMsg )
		{
			argv[1] = mx->LastActionMsg();
			argv[0] = (s32)1 ;																	
			return MX_OK;
		}

	
		static mxcommand_t mx_text[] = {
			{"Number",			2, OnTextNumber,			{variant::vnumber, variant::vnumber} },	// TMP: New !
			{"NumberPart",		1, OnTextNumberPart,		{variant::vnumber} },
			{"Energy",			1, OnTextEnergy,			{variant::vnumber} },
			{"Fear",			1, OnTextFear,				{variant::vnumber} },
			{"Courage",			1, OnTextCourage,			{variant::vnumber} },
			{"CharRecruitMen",	3, OnTextCharRecruitMen,	{arguments::character, arguments::stronghold, variant::vnumber} },
			{"CharPostMen",		3, OnTextCharPostMen,		{arguments::character, arguments::stronghold, variant::vnumber} },
			{"CharTime",		1, OnTextCharTime,			{arguments::character} },
			{"CharEnergy",		1, OnTextCharEnergy,		{arguments::character} },
			{"CharCourage",		1, OnTextCharCourage,		{arguments::character} },
			{"CharFear",		1, OnTextCharFear,			{arguments::character} },
			{"CharObject",		1, OnTextCharObject,		{arguments::character} },
			{"CharDeath",		1, OnTextCharDeath,			{arguments::character} },
			{"CharBattle",		1, OnTextCharBattle,		{arguments::character} },
			{"CharArmy",		1, OnTextCharArmy,			{arguments::character} },
//			{"CharAttributes",	1, OnTextCharAttributes,	{arguments::character} },
//			{"CharFoe",			1, OnTextCharFoe,			{arguments::character} },
//			{"CharLiege",		1, OnTextCharLiege,			{arguments::character} },
			{"CharLocation",	1, OnTextCharLocation,		{arguments::character} },
			{"Stronghold",		1, OnTextStronghold,		{arguments::stronghold} },
		//	{"ArmyTotal",		1, OnTextArmyTotal,			{const mxCArmyTotal* army} },
			{"Location",		1, OnTextLocation,			{arguments::location} },
			{"Area",			1, OnTextArea,				{arguments::area} },
			{"Object",			1, OnTextObject,			{arguments::objectinfo} },
			{"TerrainPlural",	1, OnTextTerrainPlural,		{arguments::terrain} },
			{"Terrain",			1, OnTextTerrain,			{arguments::terrain} },
			{"SpecialStrings",	2, OnTextSpecialStrings,	{variant::vnumber, arguments::character} },
			{"LastActionMsg",	0, OnLastActionMsg,			 },								// TMP: New !
			{"Purge",			0, OnTextPurge,				 },								// TMP: New !
		};


		MXRESULT mxscenario::Text ( const string& arg, variant* argv, u32 argc )
		{
			return mx->ProcessCommand ( mx_text, NUMELE(mx_text), arg, argv, argc );
		}

        mxcharacter* mxscenario::CurrentMoonringWearer ( void )
        {
            if ( IsFeature(SF_MOONRING) ) {
				mxobject* moonring = (mxobject*)mx->EntityByName("OB_MOONRING");
				return moonring!=NULL ? WhoHasObject(moonring) : NULL ;
			}
            return NULL ;
        }

		mxcharacter* mxscenario::MoonringWearer( void ) 
		{
			if ( IsFeature(SF_MOONRING) ) {
				for ( int ii=0; ii<sv_characters; ii++ ) {
					mxcharacter* character = mx->CharacterById(ii+1);
					if ( character->IsAllowedMoonring() && character->IsAlive() )
						return character ;
				}
			}
			return NULL ;
		}

		void mxscenario::DeadCharactersDropObjects( void )
		{
			for ( int ii=0; ii<sv_characters; ii++ ) {
				mxcharacter* character = mx->CharacterById(ii+1);
				if ( character->IsDead() && character->carrying ) {
					if ( character->carrying->IsUnique() )
						character->Cmd_DropObject() ;
				}
			}
		}
    
        void mxscenario::CheckMoonringWearerDead ( void )
        {
            if ( !IsFeature(SF_MOONRING) )
                return;
            
            mxcharacter* moonringcarrier = CurrentMoonringWearer();
            if ( moonringcarrier != NULL )
                return;
            
            for ( int ii=0; ii<sv_characters; ii++ ) {
                mxcharacter* character = mx->CharacterById(ii+1);
                if ( character->IsAllowedMoonring() && character->IsAlive() ) {
                    // if character is alive
                    // and they can carry the moonring
                    // then remove them from any grouping
                    
                    if ( character->IsFollowing() )
                        character->Cmd_UnFollow(character->Following());
                    
                    if ( character->HasFollowers() ) {
                        for ( int jj=0; jj<sv_characters; jj++ ) {
                            mxcharacter* follower = mx->CharacterById(jj+1);
                            if ( follower->Following() == character )
                                follower->Cmd_UnFollow(character);
                        }
                    }
                    
                }
            }
            
            
        }
    

		mxgridref mxscenario::FindLookingTowards( mxgridref loc, mxdir_t dir )
		{
		int			ii;
		mxloc       mapsqr;
            
			for (ii = 0; ii < sv_lookforwarddistance; ii++) {
				loc += dir ;
				mapsqr = mx->gamemap->GetAt(loc);
				if ( mapsqr.IsInteresting())
                    return loc;
#if defined(_DDR_)
                if ( mapsqr.IsMisty() )
                    return loc;
#endif
			}

			return loc ;
		}


		void mxscenario::ResetMapArmies ( void )
		{
			RemoveMapArmies();
			SetMapArmies();
		}

		void mxscenario::SetMapArmies ( void )
		{
		int				ii;
		mxcharacter*		character;
		mxregiment*		regiment;

			for (ii = 0; ii < sv_characters; ii++) {
				character = mx->CharacterById(ii+1) ;
#if defined(_DDR_)
				if ( !character->IsInTunnel() ) {
				if ( character->IsAlive() && !character->IsHidden() ) {
#endif
					if ( character->warriors.Total()+character->riders.Total() ) {
                            mx->gamemap->SetLocationArmy(character->Location(),1);
					}
					mx->gamemap->SetLocationCharacter(character->Location(),1);
#if defined(_DDR_)
				}
				}
#endif
			}
#if !defined(_DDR_)
            mxstronghold*	stronghold;
			for (ii = 0; ii < sv_strongholds; ii++) {
				stronghold=mx->StrongholdById(ii+1);
				if ( stronghold->Total() )
					mx->gamemap->SetLocationArmy(stronghold->Location(),1);
			}
#endif

			for (ii = 0; ii < sv_regiments; ii++) {	
				regiment=mx->RegimentById(ii+1);
				if ( regiment->Total() )
					mx->gamemap->SetLocationArmy(regiment->Location(),1);
			}

		}


		void mxscenario::RemoveMapArmies ( void )
		{
		int	ii;
			for (ii = 0; ii < sv_characters; ii++) {
				mx->gamemap->SetLocationArmy(mx->CharacterById(ii+1)->Location(),0);
				mx->gamemap->SetLocationCharacter(mx->CharacterById(ii+1)->Location(),0);
			}

			for (ii = 0; ii < sv_strongholds; ii++)
				mx->gamemap->SetLocationArmy(mx->StrongholdById(ii+1)->Location(),0);

			for (ii = 0; ii < sv_regiments; ii++)
				mx->gamemap->SetLocationArmy(mx->RegimentById(ii+1)->Location(),0);
		}

		void mxscenario::LookInDirection( mxgridref loc, mxdir_t dir, BOOL isintunnel )
		{
		
		panloc_t*	pview;
		int			ii;
		int			count;

            loc_t looked_at = loc + dir ;
            
#if defined(_DDR_)
            //
            if ( isintunnel ) {
                mx->gamemap->SetTunnelVisible(loc, true);
                if ( mx->gamemap->IsTunnel(looked_at))
                    mx->gamemap->SetTunnelVisible(looked_at, true);
                return;
            }
#endif
            mx->gamemap->SetLocationVisible(loc, true);
			
            mx->gamemap->SetLocationLookedAt(looked_at, true);
            
            
            
            
			count = mx->gamemap->GetPanoramic ( loc, dir, &pview );

			for ( ii=0; ii<count; ii++ ) {
#if defined(_DDR_)
				mxloc& mapsqr = mx->gamemap->GetAt(pview[ii].location);
                if ( mapsqr.flags & lf_mist )
                    continue;
#endif
				// if there is an army here then we need to draw the army
				//info::terrain* tinfo = TerrainById(map.terrain);

				if ( pview[ii].size < 4 ) {
                    mx->gamemap->SetLocationVisible(pview[ii].location, true);
                }
			}
            
		

		}


		void mxscenario::SetCharsLooking( void )
		{
			// setup the initial stuff that characters looking will do
			for ( int ii=0; ii<sv_characters; ii++ ) {
				mxcharacter* character = mx->CharacterById(ii+1);
				if ( character->IsRecruited() ) {
					character->Cmd_LookDir ( character->Looking() );
					character->memory.Update();
					character->EnterLocation ( character->Location() );
				}

			}
		}

		mxcharacter* mxscenario::WhoHasObject( mxobject* object ) const
		{
#if defined(_DDR_)
            return (mxcharacter*)object->carriedby ;
#endif
			for ( int ii=0; ii<sv_characters; ii++ ) {
				mxcharacter* character = mx->CharacterById(ii+1);
				if ( character->carrying == object )
					return character ;
			}
			return NULL ;
		}


		BOOL mxscenario::DropObject ( mxgridref loc, mxobject* obj )
		{
#if defined(_DDR_)
            if ( obj->IsUnique() ) {
                obj->Location( loc );
                mx->gamemap->SetObject( loc, true );
                return true;
            }
#endif
			mx->gamemap->GetAt ( loc ).object = obj ? obj->Id() : OB_NONE ;
			return TRUE ;
		}


		mxobject* mxscenario::PickupObject ( mxgridref loc )
		{
#if defined(_DDR_)
            if ( mx->gamemap->GetAt ( loc ).HasObject() ) {
                mxobject* object = FindObjectAtLocation(loc);
                mx->gamemap->SetObject(loc, false);
                object->Location(mxgridref(0, 0));
                return object;
            }
            return NULL;
#endif

            mxthing_t oldobject ;

			oldobject = (mxthing_t)mx->gamemap->GetAt ( loc ).object ;

			mx->gamemap->GetAt ( loc ).RemoveObject();
			
			return mx->ObjectById(oldobject) ;
		}

		BOOL mxscenario::InCharactersMemory ( mxitem* item ) 
		{
		mxcharacter* character;
			for ( int ii=0; ii<sv_characters; ii++ ) {
				character = mx->CharacterById(ii+1);
				if ( character->memory.IsMemorised(item) )
					return TRUE;
			}
			return FALSE;
		}


		void mxscenario::ClearFromMemory ( mxgridref loc )
		{
		
		int			ii;
		mxcharacter* character;
		mxfragment* item;

			for ( ii=0; ii<sv_characters; ii++ ) {
				character = mx->CharacterById(ii+1);
				item = character->memory.IsMemorised(loc,RA_DOOMGUARD);
				if ( item ) {
					character->memory.DeleteFragment ( item );
				}
				item = character->memory.IsMemorised(loc,RA_FREE);
				if ( item ) {
					character->memory.DeleteFragment ( item );
				}
			}
		
		}

		MXRESULT mxscenario::GetLocInfo ( mxid id, mxlocinfo*& info )
		{
			if ( ID_TYPE(id) == IDT_LOCATION ) {
				CONVERT_GRIDREF(id,loc);
				info = new mxlocinfo(loc,NULL,0);
				return MX_OK;
			}else if ( ID_TYPE(id) == IDT_STRONGHOLD ) {
				CONVERT_STRONGHOLD_ID(id,stronghold);
				info = new mxlocinfo(stronghold->Location(),NULL,0);
				return MX_OK;
			}else if ( ID_TYPE(id) == IDT_ROUTENODE ) {
				CONVERT_ROUTENODE_ID(id,routenode);
				info = new mxlocinfo(routenode->Location(),NULL,0);
				return MX_OK;
			}else if ( ID_TYPE(id) == IDT_CHARACTER ) {
				CONVERT_CHARACTER_ID(id,character);
				info = character->GetLocInfo();
				return MX_OK;
			}
			return MX_FAILED;
		}



		BOOL mxscenario::GetCharactersAvailableForCommand ( u32 mode, mxgridref loc, collections::entities& collection )
		{
		int			count;
		int			ii;
		mxcharacter*	c=NULL;
		mxobject*		moonring=NULL;
		mxcharacter*	moonringcarrier=NULL;
		
			collection.Clear();

            // don't return DOOMDARK
            // TODO: Create a flag for this!!!!
            mxcharacter* doomdark = (mxcharacter*)mx->EntityByName("CH_DOOMDARK");
            
            
			if ( IsFeature(SF_MOONRING) ) {
				moonring = (mxobject*)mx->EntityByName("OB_MOONRING");
				//moonringcarrier = moonring ? WhoHasObject(moonring) : NULL ;
                moonringcarrier = CurrentMoonringWearer();

			}

			count=0;
			for ( ii=0; ii<sv_characters; ii++ ) {

				c = mx->CharacterById(ii+1);

				if ( mode != CMDG_ALL ) {

					if ( !c->IsRecruited() )
						continue;

					if ( IsFeature(SF_MOONRING) ) {
						if ( moonring && moonringcarrier==NULL && !c->IsAllowedMoonring() )
							continue;
					}

					if ( mode==CMDG_WAITING ) {
						if ( c->IsWaiting() || c->IsNight() || c->IsDead() )
							continue;
					}else if ( mode==CMDG_CURRENTLOC ) {
						if ( c->Location() != loc )
							continue;
					}

				}else{
                    if ( c == doomdark )
                        continue;
                }

				collection += c;

			}

			return TRUE ;
		}


	// only recruited/moonring
	// above ground
	// underground

		u32 mxscenario::FindCharactersAtLocation ( mxgridref loc, collections::entities& characters, flags32_t flags )
		{
		int					ii;
		mxcharacter*	moonringcarrier=NULL;
		mxcharacter*	c=NULL;
		mxobject*		moonring=NULL;
		int					count;
		BOOL				in_tunnel = ( flags & slf_tunnel ) == slf_tunnel;

			// TODO character needs a visible flag
			mxcharacter* ch_doomdark = (mxcharacter*)mx->EntityByName("CH_DOOMDARK");

			count=0;

			if ( IsFeature(SF_MOONRING) ) {
				moonring = (mxobject*)mx->EntityByName("OB_MOONRING");
				//moonringcarrier = moonring ? WhoHasObject(moonring) : NULL ;
                moonringcarrier = CurrentMoonringWearer();

            }

			characters.Create(MAX_CHARACTERS_INLOCATION);

			for (ii = 0; ii < sv_characters; ii++) {
				c = mx->CharacterById(ii+1);
				if ( c==NULL ) //|| character->IsDead() || character->IsHidden() )
					continue;
				if ( c == ch_doomdark )
					continue;
				if ( c->Location() != loc )
					continue;

                
                
				// check for tunnel
				if ( c->IsInTunnel() != in_tunnel )
					continue;

				if ( !(flags & slf_all) ) {
					if ( !c->IsRecruited() )
						continue;	
					if ( IsFeature(SF_MOONRING) ) {
						if ( moonring && moonringcarrier==NULL && !c->IsAllowedMoonring() )
							continue;
					}
				}

				characters += c ;
			}

			return characters.Count();
		}


		u32 mxscenario::FindArmiesAtLocation ( mxgridref loc, u32& enemies, u32& friends, flags32_t flags )
		{
		int			ii;
		mxcharacter* character;

			enemies=0;
			friends=0;

			for ( ii=0; ii<sv_characters; ii++ ) {
				character = mx->CharacterById(ii+1);
				if ( character->memory.IsMemorised(loc,RA_DOOMGUARD) )
					enemies++;
				if ( character->memory.IsMemorised(loc,RA_FREE) )
					friends++;
				if ( character->Location() == loc && character->HasArmy() )
					friends++;
			}


			return friends+enemies ;
		}

#if defined(_DDR_)
        void mxscenario::PlaceObjectsOnMap ( void )
        {
            mxobject* object;
			mxgridref loc;
            for ( int ii=0; ii<sv_objects; ii++ ) {
				object = mx->ObjectById(ii+1);
                if ( object->IsUnique() && object->IsRandomStart() ) {
                    BOOL found=false;
                    while ( !found ) {
                        loc.x = random(0,mx->gamemap->Size().cx-1);
                        loc.y = random(0,mx->gamemap->Size().cy-1);
                        if ( !mx->gamemap->HasObject(loc) && !mx->gamemap->IsLocationBlock(loc)  )
                            found=true;
                    }
                    object->Location(loc);
                    mx->gamemap->SetObject( loc, true );
                }
            }
        }
    
    mxobject* mxscenario::FindObjectAtLocation ( mxgridref loc )
    {
        if ( !mx->gamemap->HasObject(loc) )
            return NULL;
        
        mxobject* object;
        for ( int ii=0; ii<sv_objects; ii++ ) {
            object = mx->ObjectById(ii+1);
            if ( object->IsCarried() )
                continue;
            if ( object->Location() == loc )
                return object;
        }
        return NULL;
    }
    
    mxstronghold* mxscenario::StrongholdFromLocation ( mxgridref loc )
    {
		mxloc& mapsqr = mx->gamemap->GetAt ( loc );
        if ( !(mapsqr.flags&lf_stronghold) )
            return NULL;
        
        mxstronghold* stronghold;
        for ( int ii=0; ii<sv_strongholds; ii++ ) {
            stronghold = mx->StrongholdById(ii+1);
            if ( stronghold->Location() == loc )
                return stronghold;
        }
        return NULL;
    }
    
    mxterrain_t mxscenario::NormaliseTerrain( mxterrain_t t) const
    {
        return t;
    }
    
#endif

    
    void mxscenario::initialiseAfterCreate( void )
    {
        MXTRACE( "Init Map" );
        SetMapArmies();
        SetCharsLooking();
        
#if defined(_DDR_)
        for ( int ii=0; ii<sv_characters; ii++ ) {
            mxcharacter* c = mx->CharacterById(ii+1);
            c->lastlocation=c->Location();
        }
#endif
        
        MXTRACE( "Place Strongholds On Map");
        // mark the strongholds onto the map
        for (int ii = 0; ii < sv_strongholds; ii++) {
            mxstronghold* stronghold=mx->StrongholdById(ii+1);
            mxloc& mapsqr = mx->gamemap->GetAt ( stronghold->Location() );
            mapsqr.flags|=lf_stronghold;
        }
        
        MXTRACE( "Place RouteNodes On Map");
        // mark the routenodes onto the map
        for (int ii = 0; ii < sv_routenodes; ii++) {
            mxroutenode* routenode=mx->RouteNodeById(ii+1);
            mxloc& mapsqr = mx->gamemap->GetAt ( routenode->Location() );
            mapsqr.flags|=lf_routenode;
        }

    }
    

    void mxscenario::GiveGuidance( mxcharacter* character, s32 hint )
    {
        BOOL mikeseek = (hint == 1);
        
        BOOL found = false;
        if ( chance(0.80f) || mikeseek ) {
            while ( !found  ) {
                int id = random(1,sv_characters-1);
                
                mxcharacter* c = mx->CharacterById(id);
                
                if ( mikeseek )
                    c = (mxcharacter*)mx->EntityByName("CH_MIDWINTER");
                
                // lets not find doomdark
                if ( c->Race()==RA_DOOMGUARD )
                    continue;
                
                collections::entities collection;
                
                mx->scenario->GetDefaultCharacters ( collection );
                if ( collection.FindSymbol(c->Symbol()) == NULL ) {
                    chilli::lib::strcat ( (LPSTR)mx->LastActionMsg(),
                                         mx->text->CookText((LPSTR)mx->text->SystemString(SS_GUIDANCE1),c) );
                    found=TRUE;
                }
                
                
                
                
            }
        }
        if ( !found ) {
            int msg = random(0,sv_guidance.Count()-1);
            chilli::lib::strcat ( mx->LastActionMsg(),
                                 mx->text->CookText((LPSTR)mx->text->SystemStringById(sv_guidance[msg]))) ;
        }

    }

    
    
    
    

	//}
	// namespace scenarios
}
// namespace tme





