#include "cheat.h"
#include "../classes/minecraft/minecraft.h"
#include "../classes/minecraft/entity/entity.h"
#include "settings.h"
#include "../utils/Math.h"
#include "../menu/menu.h"
namespace Function {
    bool ESP(){
        
        jobject objectWorld = Minecraft::world.theObject();
        if(objectWorld == NULL){
            jni_mc->env->DeleteLocalRef(objectWorld);
            return FALSE;
        }
       
        std::vector<Entity> entities = Minecraft::world.playerEntities();
        for(int i = 0;i < entities.size(); i++){
            if(entities[i].IsLocalPlayer()){
                jni_mc->env->DeleteLocalRef(entities[i].GetMemory());
                continue;
            }
            if(Settings::Cheat::isGlowEsp)
                entities[i].SetGlowing(true);
            // Vector3 lastTick = entities[i].LastTickPosition();
            // Vector3 pos = entities[i].Position();
            // Vector3 static_pos = Minecraft::local.GetStaticPosition();

            // float part = Minecraft::render.RenderPartialTicks();
            // Vector3 position_entiy = {lastTick + (pos - lastTick) * part};

            // Matrix matrix = Minecraft::stack.GetMatrix(static_pos);
            // Vector2 window_size = Minecraft::WindowSize();


            // std::cout << matrix.m00 << std::endl;
            // std::cout << matrix.m01 << std::endl;
            // std::cout << matrix.m02 << std::endl;
            // std::cout << matrix.m03 << std::endl;
            // std::cout << matrix.m10 << std::endl;

            // // //Minecraft::render.DrawBox(matrix,static_pos,position_entiy);
            // Vector2 position_screan = Minecraft::render.WorldToScrean(position_entiy,matrix,window_size);
            // ImGui::GetForegroundDrawList()->AddText({(float)position_screan.x,(float)position_screan.y},ImColor(255,255,255,255),"Name");

            jni_mc->env->DeleteLocalRef(entities[i].GetMemory());
        }
        jni_mc->env->DeleteLocalRef(objectWorld);
        return FALSE;
    }

    bool HitBox() {
        if(Settings::Cheat::isHitBox){
            jobject objectWorld = Minecraft::world.theObject();
            if(objectWorld == NULL){
                jni_mc->env->DeleteLocalRef(objectWorld);
                return FALSE;
            }

            std::vector<Entity> entities = Minecraft::world.playerEntities();
            for(int i = 0;i < entities.size(); i++){
                if(entities[i].IsLocalPlayer()){
                    jni_mc->env->DeleteLocalRef(entities[i].GetMemory());
                    continue;
                }
                Vector3 pos = entities[i].Position();

                jobject box = entities[i].AxisAlignedBB(pos.x - Settings::Cheat::size_hit_box,
                entities[i].MinY(),
                pos.z - Settings::Cheat::size_hit_box,
                pos.x + Settings::Cheat::size_hit_box,
                entities[i].MaxY(),
                pos.z + Settings::Cheat::size_hit_box
                );

                entities[i].SetBoundingBox(box);

                jni_mc->env->DeleteLocalRef(entities[i].GetMemory());
                jni_mc->env->DeleteLocalRef(box);
            }
            jni_mc->env->DeleteLocalRef(objectWorld);
        }
        return FALSE;
    }

    bool AutoSprint(){
        if(Settings::Cheat::isSprint){
            jobject player = Minecraft::local.objectPlayer();
            if(player == NULL)
            {   
                jni_mc->env->DeleteLocalRef(player);
                return FALSE;
            }

            if(GetAsyncKeyState('W') & 0x8000)
                Minecraft::local.SetSprint(true);

            jni_mc->env->DeleteLocalRef(player);
        }
        
    }
    bool WorldTime(){
        if(Settings::Cheat::isWorldTime){
            jobject player = Minecraft::local.objectPlayer();
            if(player == NULL)
            {   
                jni_mc->env->DeleteLocalRef(player);
                return FALSE;
            }

            Minecraft::world.SetWorldTime(Settings::Cheat::time_world);

            jni_mc->env->DeleteLocalRef(player);
        }
        
    }
    bool AimBot(){
        if(Settings::Cheat::isAimBot){
            jobject player = Minecraft::local.objectPlayer();
            if(player == NULL)
            {   
                jni_mc->env->DeleteLocalRef(player);
                return FALSE;
            }
            std::vector<Entity> entities = Minecraft::world.playerEntities();
            double distance = 10000;

            Vector2 vec_p = {0,0};
            jobject target = nullptr;
            for(int i = 0;i < entities.size(); i++){
                if(entities[i].IsLocalPlayer()){
                    jni_mc->env->DeleteLocalRef(entities[i].GetMemory());
                    continue;
                }
                double new_distance = entities[i].Distance(player);
                if(new_distance > distance)
                {
                    jni_mc->env->DeleteLocalRef(entities[i].GetMemory());
                    continue;
                }
                distance = new_distance;
                Vector3 pos = entities[i].Position();
                Vector3 pos_local = Entity(player).Position();
                Vector2 vec = rotation(pos,pos_local,Entity(player).GetEyeHeight());    
                vec_p = vec;

                if(target != nullptr)
                    jni_mc->env->DeleteLocalRef(target);

                target = entities[i].GetMemory();
                
            }   
            if (vec_p.x != 0 && vec_p.y != 0){
                Minecraft::local.SetRotationPitch(vec_p.y);
                Minecraft::local.SetRotationYaw(vec_p.x);

                if(Settings::Cheat::AimBot::isHud)
                {
                    ImGui::SetNextWindowSize({150.f,50.f});
                    ImGui::Begin(xorstr("HUD"),NULL,ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar);
                    
                    Entity entity = target;

                    ImGui::SetCursorPos({10,5});
                    ImGui::PushFont(ImGui_Local::Menu::Font::verdana_font);
                    ImGui::Text(entity.GetName());
                    ImGui::PopFont();

                    ImGui::DrawBox(xorstr("#hud"),{120.f,10.f},ImColor(17,17,17,255),10.f);
                    ImGui::SetCursorPosY(25);
                    ImGui::DrawBox(xorstr("#health"),{entity.GetHealth() * 6,10.f},ImGui_Local::Menu::color_theam,10.f);
                    
                    ImGui::End();

                  
                    jni_mc->env->DeleteLocalRef(target);
                }
            }
            jni_mc->env->DeleteLocalRef(player);
        }
    }
}

bool Cheat::start(){
    if(!Settings::Cheat::list_module.init){
        Settings::Cheat::list_module.Add(xorstr("EPS").decrypt(),&Settings::Cheat::isGlowEsp);
        Settings::Cheat::list_module.Add(xorstr("AimBot").decrypt(),&Settings::Cheat::isAimBot);
        Settings::Cheat::list_module.Add(xorstr("AutoSprint").decrypt(),&Settings::Cheat::isSprint);
        Settings::Cheat::list_module.Add(xorstr("HitBox").decrypt(),&Settings::Cheat::isHitBox);
        Settings::Cheat::list_module.Add(xorstr("WorldTime").decrypt(),&Settings::Cheat::isWorldTime);
        Settings::Cheat::list_module.init = true;
    }
    
    Function::ESP();
    Function::HitBox();
    Function::AutoSprint();
    Function::WorldTime();
    Function::AimBot();
    return TRUE;
}


bool Cheat::unload(){
    jobject objectWorld = Minecraft::world.theObject();
    if(objectWorld == NULL){
        jni_mc->env->DeleteLocalRef(objectWorld);
        return FALSE;
    }

    std::vector<Entity> entities = Minecraft::world.playerEntities();
    for(int i = 0;i < entities.size(); i++){
        if(entities[i].IsLocalPlayer()){
            jni_mc->env->DeleteLocalRef(entities[i].GetMemory());
            continue;
        }
       
        entities[i].SetGlowing(false);
      
        Vector3 pos = entities[i].Position();

         jobject box = entities[i].AxisAlignedBB(pos.x - 0.3,
            entities[i].MinY(),
            pos.z - 0.3,
            pos.x + 0.3,
            entities[i].MaxY(),
            pos.z + 0.3
            );

        entities[i].SetBoundingBox(box);
        jni_mc->env->DeleteLocalRef(box);
        jni_mc->env->DeleteLocalRef(entities[i].GetMemory());
    }
    jni_mc->env->DeleteLocalRef(objectWorld);
    return TRUE;
}