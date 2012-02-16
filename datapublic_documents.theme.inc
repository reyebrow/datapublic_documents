<?php

/**
 * Provides theming resources to be used in the Document content type.
 *
 * @todo
 *  --  implement rdf attributes in created and submitted times in node template
 */


/**
 * Implements theme_file_link().
 *
 * Specifically, rewrites it to return the markup and content just so.
 */
function datapublic_documents_file_link($variables) {
  $file = $variables['file'];
  $icon_directory = $variables['icon_directory'];

  $url = file_create_url($file->uri);
  $icon = theme('file_icon', array('file' => $file, 'icon_directory' => $icon_directory));

  // Set options as per anchor format described at
  // http://microformats.org/wiki/file-format-examples
  $options = array(
    'attributes' => array(
      'type' => $file->filemime . '; length=' . $file->filesize,
    ),
  );

  // Figure out how the output will look:
  $field_pattern = '<div class="row"><div class="nice large radius white button">%s<br />%s %s</div></div>';
  // Get the variables for sprintf:
  $link = l(t('Download Now'), $url, $options);
  $file_size = format_size($file->filesize);
  $file_extension = strtoupper(pathinfo($url, PATHINFO_EXTENSION));
  // Return the markup:
  return sprintf($field_pattern, $link, $file_size, $file_extension);
} // datapublic_documents_file_link()


/**
 * Implements of hook_theme().
 *
 * @todo
 *  --  it seems that, in some circumstances, $existing['node'] doesn't exist
 *      when this function runs (module weight? phase of the moon?), so
 *      ensure that it's an array, and that it gets the right properties, OR
 *      find out how to make damned sure node is present before this!
 *  --  confirm that theme_file_link() will override this if used in themes
 */
function datapublic_documents_theme($existing) {
  // Provide template for document content type:
  $document = $existing['node'] || array();
  $document['path'] = drupal_get_path('module', 'datapublic_documents') . '/theme';
  $document['template'] = 'node--document';
  // Override theming function for file link--this could also be done using
  // hook_theme_registry_alter():
  $file_link = $existing['file_link'];
  $file_link['function'] = 'datapublic_documents_file_link';
  return array(
    'node__document' => $document,
    'file_link' => $file_link,
  );
} // datapublic_documents_theme()