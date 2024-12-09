bool Asteroid::collidesWith(CCSprite *obj)
{
    // Create two rectangles with CGRectMake, using each sprite's x/y position and width/height
    CCRect ownRect = CCRectMake(this->getPosition().x - this->getContentSize().width / 2, 
                                this->getPosition().y - this->getContentSize().height / 2, 
                                this->getContentSize().width, 
                                this->getContentSize().height);
    
    CCRect otherRect = CCRectMake(obj->getPosition().x - obj->getContentSize().width / 2, 
                                obj->getPosition().y - obj->getContentSize().height / 2, 
                                obj->getContentSize().width, 
                                obj->getContentSize().height);
    
    // Feed the results into CGRectIntersectsRect() which tells if the rectangles intersect (obviously)
    return CCRect::CCRectIntersectsRect(ownRect, otherRect);
}