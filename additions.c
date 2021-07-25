void
focusdown(const Arg *arg){
	Client *c = selmon->sel;
	int targetX = c->x;
	int targetY = c->y + c->h + selmon->gappih; 
	Client * iter; 
	Client * bestCandidate = NULL;
	int bestDevX = 99999999;
	int bestDevY = 99999999;
	
	if((c->y + c->h + selmon->gappoh) == selmon->wh) return;
	
	for(iter = selmon->clients; iter != NULL; iter = iter->next){
		if(iter == c ) 		 continue;
		if(!ISVISIBLE(iter)) continue;

		int iterWX = iter->x + iter->w;

		if(iter->y == targetY
			  || iter->y == (targetY + selmon->gappih)
			  || iter->y == (targetY + selmon->gappoh)
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
focusup(const Arg *arg){
	Client *c = selmon->sel;
	int targetX = c->x;
	int targetY = c->y - selmon->gappih;
	Client * iter; 
	Client * bestCandidate = NULL;
	int bestDevX = 99999999;
	int bestDevY = 99999999;
	
	if(c->y == (selmon->wy + selmon->gappoh)) return;
	
	for(iter = selmon->clients; iter != NULL; iter = iter->next){
		if(iter == c ) 		 continue;
		if(!ISVISIBLE(iter)) continue;

		int iterWX = iter->x + iter->w;
		int iterHY = iter->y + iter->h;

		if(iterHY == targetY
			  || iterHY == (targetY + selmon->gappih)
			  || iterHY == (targetY + selmon->gappoh)
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
focusleft(const Arg *arg){
	Client *c = selmon->sel;
	int targetX = c->x - selmon->gappiv;
	int targetY = c->y;
	Client * iter; 
	Client * bestCandidate = NULL;
	int bestDevX = 99999999;
	int bestDevY = 99999999;
	
	if(c->x == selmon->gappov) return;

	for(iter = selmon->clients; iter != NULL; iter = iter->next){
		if(iter == c ) 		 continue;
		if(!ISVISIBLE(iter)) continue;

		int iterWX = iter->x + iter->w;
		

		if(iterWX == targetX 
			|| (iterWX  == (targetX - selmon->gappiv )) 
			|| (iterWX  == (targetX - selmon->gappov )) 
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
focusright(const Arg *arg){
	Client *c = selmon->sel;
	int targetX = c->x + c->w + selmon->gappiv;
	int targetY = c->y;
	Client * iter; 
	Client * bestCandidate = NULL;
	int bestDevX = 99999999;
	int bestDevY = 99999999;
	
	if(c->x == selmon->gappov) return;

	for(iter = selmon->clients; iter != NULL; iter = iter->next){
		if(iter == c ) 		 continue;
		if(!ISVISIBLE(iter)) continue;

		int iterWX = iter->x + iter->w;
		

		if(iter->x == targetX 
			|| (iter->x  == (targetX - selmon->gappiv )) 
			|| (iter->x  == (targetX - selmon->gappov )) 
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