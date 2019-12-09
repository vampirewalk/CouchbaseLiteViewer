//
//  QueryResultController.h
//  Couchbase Lite Viewer
//
//  Created by Jens Alfke on 8/29/12.
//  Copyright (c) 2012 Couchbase, Inc. All rights reserved.
//

#import <Cocoa/Cocoa.h>

typedef NS_ENUM(NSInteger, DataField) {
    DocID = 0,
    Type = 1,
};

@interface QueryResultController : NSObject <NSOutlineViewDataSource, NSOutlineViewDelegate>

@property (copy) CBLQuery* query;
@property (weak) NSOutlineView* outline;
@property BOOL showDeleted;

- (void) registerPath: (NSArray*)path forColumn: (NSTableColumn*)column;
- (void) unregisterColumn: (NSTableColumn*)column;

- (NSArray*) selectedDocuments;
- (BOOL) selectDocument: (CBLDocument*)doc;

- (IBAction) newDocument: (id)sender;
- (IBAction) deleteDocument: (id)sender;
- (IBAction) copy:(id)sender;
- (void)searchField:(DataField)field withText:(NSString *)text;

@end
