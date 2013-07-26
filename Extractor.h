//
//  Exctractor.h
//  ExtractorAction
//
//  Created by Vitaly Davidenko on 12/10/06.
//  Copyright 2006 Vitaly Davidenko.
//
//  Apple Public Source License
//  http://www.opensource.apple.com/apsl/
//
//	Updated and refactored by Rob Rohan on 2007-09-18

#import <Cocoa/Cocoa.h>
#import <WebKit/WebKit.h>

@interface Extractor : NSObject 
{
	WebResource *  m_mainResource;
	NSMutableSet * m_resources;
	
	//in m_resourceLookupTable HTML resource can be stored with relative or 
	//absolute path m_resourceLookupTable contains several keys for each resource 
	// (as least 2: absolute and relative paths)
	NSMutableDictionary * m_resourceLookupTable;
}

/**
 * load web archive file
 */
- (void)loadWebArchiveAtURL:(NSURL *)webArchiveURL;

/**
parse WebArchive (can be main archive, or subframeArchives)
added by Robert Covington to handle archives with subframeArchives
*/
-(void) parseWebArchive:(WebArchive *) archiveToParse; 

/**
 * add resource to resource table
 */
- (void) addResource:(WebResource *) resource;


/**
 * extract to directory
 */
- (NSURL *)extractResourcesToURL:(NSURL *)url;

/**
 * private method
 * extract resource to existing packagePath (using outputResource)
 * (packagePath the same as path of extractResources message)
 */
- (void) extractResource:(WebResource *)resource packageURL:(NSURL *)url;

/**
 * protected method
 * write resource data to filePath
 * Parent directory of filePath should exists
 */
-(void) outputResource:(WebResource *)resource fileURL:(NSURL *)filePath packageURL:(NSURL *)packageURL;

@property (copy)	NSString *entryFileName;
@property (assign)	int	contentKind;
@property (copy)	NSString *URLPrepend;

@end
