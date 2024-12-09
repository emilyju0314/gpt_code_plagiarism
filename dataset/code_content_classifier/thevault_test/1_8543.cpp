synchronized (filterer_mutex) {
        if (filterer != NULL) {
          bool filter = false;
          struct FilterVisitor : EventVisitor
          {
            explicit FilterVisitor(bool* _filter) : filter(_filter) {}

            virtual void visit(const MessageEvent& event)
            {
              *filter = filterer->filter(event);
            }

            virtual void visit(const DispatchEvent& event)
            {
              *filter = filterer->filter(event);
            }

            virtual void visit(const HttpEvent& event)
            {
              *filter = filterer->filter(event);
            }

            virtual void visit(const ExitedEvent& event)
            {
              *filter = filterer->filter(event);
            }

            bool* filter;
          } visitor(&filter);

          event->visit(&visitor);

          if (filter) {
            delete event;
            continue; // Try and execute the next event.
          }
        }
      }