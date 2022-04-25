static void focusup();
static void focusdown();
static void focusright();
static void focusleft();

#define DIRECT_THRESHOLD 10

void
focusdown(){
	Client *c = selmon->sel;
	int targetX = c->x;
	int targetY = c->y + c->h + selmon->gappx; 
	Client * iter; 
	Client * bestCandidate = NULL;
	int bestDevX = 99999999;
	int bestDevY = 99999999;
	
	if((c->y + c->h + selmon->gappx) == selmon->wh) return;

	for(iter = selmon->clients; iter != NULL; iter = iter->next){
		if(iter == c ) 		 continue;
		if(!ISVISIBLE(iter)) continue;
		if(iter->y == targetY
			  || iter->y == (targetY + selmon->gappx)
			  || iter->y == (targetY + selmon->gappx)
			  || (iter->y - targetY) < DIRECT_THRESHOLD
			)
		{
			int devX = (iter->x > targetX) ? iter->x - targetX : targetX - iter->x;
			int devY = (iter->y > targetY) ? iter->y - targetY : targetY - iter->y;
			
			if((devX < bestDevX && devY < bestDevY) || (devX == bestDevX && devY < bestDevY) || (devX < bestDevX && devY == bestDevY)){
				bestDevX = devX;
				bestDevY = devY;
				bestCandidate = iter;
			}
		}
		
	}
	if(bestCandidate) focus(bestCandidate);
}

void
focusup(){
	Client *c = selmon->sel;
	int targetX = c->x;
	int targetY = c->y - selmon->gappx;
	Client * iter; 
	Client * bestCandidate = NULL;
	int bestDevX = 99999999;
	int bestDevY = 99999999;
	
	if((c->y + selmon->gappx) == selmon->wy ) return;
	
	for(iter = selmon->clients; iter != NULL; iter = iter->next){
		if(iter == c ) 		 continue;
		if(!ISVISIBLE(iter)) continue;

		int iterHY = iter->y + iter->h;

		if(iterHY == targetY
			  || iterHY == (targetY - selmon->gappx)
			  || iterHY == (targetY - selmon->gappx)
			  || (iterHY - targetY) < DIRECT_THRESHOLD
			)
		{
			int devX = (iter->x > targetX) ? iter->x - targetX : targetX - iter->x;
			int devY = (iter->y > targetY) ? iter->y - targetY : targetY - iter->y;

			if((devX < bestDevX && devY < bestDevY) || (devX == bestDevX && devY < bestDevY) || (devX < bestDevX && devY == bestDevY)){
				bestDevX = devX;
				bestDevY = devY;
				bestCandidate = iter;
			}
		}
		
	}
	if(bestCandidate) focus(bestCandidate);
}

void
focusleft(){
	Client *c = selmon->sel;
	int targetX = c->x - selmon->gappx;
	int targetY = c->y;
	Client * iter; 
	Client * bestCandidate = NULL;
	int bestDevX = 99999999;
	int bestDevY = 99999999;
	
	if(c->x == selmon->gappx) return;

	for(iter = selmon->clients; iter != NULL; iter = iter->next){
		if(iter == c ) 		 continue;
		if(!ISVISIBLE(iter)) continue;

		int iterWX = iter->x + iter->w;
		

		if(iterWX == targetX 
			|| (iterWX  == (targetX - selmon->gappx )) 
			|| (iterWX  == (targetX - selmon->gappx )) 
			|| (iterWX - targetX) < DIRECT_THRESHOLD
			)
		{
			int devX = (iter->x > targetX) ? iter->x - targetX : targetX - iter->x;
			int devY = (iter->y > targetY) ? iter->y - targetY : targetY - iter->y;
			
			if((devX < bestDevX && devY < bestDevY) || (devX == bestDevX && devY < bestDevY) || (devX < bestDevX && devY == bestDevY)){
				bestDevX = devX;
				bestDevY = devY;
				bestCandidate = iter;
			}
		}
		
	}
	if(bestCandidate) focus(bestCandidate);
}

void
focusright(){
	Client *c = selmon->sel;
	int targetX = c->x + c->w + selmon->gappx;
	int targetY = c->y;
	Client * iter; 
	Client * bestCandidate = NULL;
	int bestDevX = 99999999;
	int bestDevY = 99999999;
	
	if((c->x + c->w + selmon->gappx) == selmon->ww) return;
    
	for(iter = selmon->clients; iter != NULL; iter = iter->next){
		if(iter == c ) 		 continue;
		if(!ISVISIBLE(iter)) continue;
        
		if(iter->x == targetX 
			|| (iter->x  == (targetX + selmon->gappx )) 
			|| (iter->x  == (targetX + selmon->gappx )) 
			|| (iter->x - targetX) < DIRECT_THRESHOLD
			)
		{
			int devX = (iter->x > targetX) ? iter->x - targetX : targetX - iter->x;
			int devY = (iter->y > targetY) ? iter->y - targetY : targetY - iter->y;
         
			if((devX < bestDevX && devY < bestDevY) || (devX == bestDevX && devY < bestDevY) || (devX < bestDevX && devY == bestDevY)){
				bestDevX = devX;
				bestDevY = devY;
				bestCandidate = iter;
			}
		}
		
	}
	if(bestCandidate) focus(bestCandidate);

}
