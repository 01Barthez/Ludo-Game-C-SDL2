#ifndef GLOBAL_H_
#define GLOBAL_H_
    
    typedef struct {
        int x;
        int y;
    } Position;
    
    void SDL_ExitWithError(const char *message); // Pour gerer les erreurs globales

#endif