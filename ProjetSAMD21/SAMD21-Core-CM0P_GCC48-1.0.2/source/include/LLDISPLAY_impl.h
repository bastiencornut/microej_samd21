/* 
 * Copyright 2011-2016 IS2T. All rights reserved.
 * Modification and distribution is permitted under certain conditions.
 * IS2T PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */
/* 
 * AUTOGENERATED by COMP-ICETEA-CGNU-ARM - 1.0.0 - DO NOT EDIT IT
 */
/* 
 * Implementation header file. Shall only be included by client implementation C files.
 */
#include <LLDISPLAY.h>
#include <stdint.h>
#include <intern/LLDISPLAY_impl.h>
// --------------------------------------------------------------------------------
// -                      Functions that must be implemented                      -
// --------------------------------------------------------------------------------

/**
 * Initialize the display.
 */
void LLDISPLAY_IMPL_initialize(void);

/**
 * Gets the display's width in pixels.<br>
 * @return the display's width in pixels. 
 */
int32_t LLDISPLAY_IMPL_getWidth(void);

/**
 * Gets the display's height in pixels.<br>
 * @return the display's height in pixels. 
 */
int32_t LLDISPLAY_IMPL_getHeight(void);

/**
 * Returns the address of the graphics buffer. This buffer will be used by the 
 * display stack to draw application drawings. This function is only called on
 * startup. In COPY and DIRECT modes, this buffer address stays the same during
 * application runtime. In SWITCH mode, this buffer address will change
 * (see {@link LLDISPLAY_flush}).
 * @return the graphics buffer address
 */
int32_t LLDISPLAY_IMPL_getGraphicsBufferAddress(void);

/**
 * Returns the start address of the buffer used to store the display stack's heap.
 * The heap can contain:
 * <ul>
 * <li>the dynamic user images,</li>
 * <li>the working buffers and the decoded images of embedded image decoders (for instance the PNG decoder)</li>
 * </ul>
 * A too small value can cause OutOfMemory errors and incomplete drawings. <br>
 * Ensure the heap start address is aligned on 32 bits or ensure the CPU can manupulates unaligned memory
 * addresses. <br>
 * @return the working buffer start address
 */
int32_t LLDISPLAY_IMPL_getWorkingBufferStartAddress(void);

/**
 * Returns the end address of the buffer used to store the display stack's heap.
 * @see LLDISPLAY_getWorkingBufferStartAddress
 * @return the working buffer end address
 */
int32_t LLDISPLAY_IMPL_getWorkingBufferEndAddress(void);

/**
 * Performs a flush: the content of given square in graphics buffer (back buffer) must be
 * displayed into LCD buffer (frame buffer). The rectangle specified by (<code>xmin</code>, 
 * <code>ymin</code>) to (<code>xmax</code>, <code>ymax</code>) is the region 
 * which has changed during last draw and only this region should be updated (dirty area).<br>
 * <br>
 * The implementation has to return the new graphics buffer address, depending on the
 * display stack mode (see UI documentation).<br>
 * <br>
 * In DIRECT mode, this action is useless because graphics and frame buffers are same
 * buffer. The buffer address to return must be equal to the given buffer address.<br>
 * <br>
 * In COPY mode, the content of given square in back buffer must be copied into LCD buffer. 
 * This function should be atomic and not block until the buffer is copied.
 * The implementation should start a DMA or another OS task to perform the copy
 * and return. The framework will ensure the dirty area has been fully copied
 * before performing a new drawing calling the function {@link LLDISPLAY_synchronize}. 
 * The buffer address to return must be equal to the given buffer address.<br>
 * <br>
 * In SWITCH mode, the implementation has to set the new display buffer address to the supplied addr. 
 * The buffers are swapped: the existing display buffer becomes the new back buffer and the supplied <code>addr</code> 
 * becomes the new display buffer. After the swap the implementation must copy the content of the new display buffer 
 * into the new back buffer. This function should be atomic and not block until the buffer is copied.
 * The implementation should start a DMA or another OS task to perform the copy
 * and return. The framework will ensure the dirty area has been fully copied<br>
 * before performing a new drawing calling the function {@link LLDISPLAY_synchronize}. 
 * The buffer address to return must be the old frame buffer address.<br>
 * <br>
 * @param sourceAddr the address of source buffer (current graphics buffer) to copy 
 * @param xmin the top-left X-coordinate of the dirty area. 
 * @param ymin the top-left Y-coordinate of the dirty area. 
 * @param xmax the bottom-right X-coordinate of the dirty area. 
 * @param ymax the bottom-right Y-coordinate of the dirty area. 
 * @return the new graphics buffer address
 * @see LLDISPLAY_synchronize
 */
int32_t LLDISPLAY_IMPL_flush(int32_t sourceAddr, int32_t xmin, int32_t ymin, int32_t xmax, int32_t ymax);

/**
 * Synchronizes the display stack drawings with the display framerate.<br>
 * This method is called by the display stack before the very first drawing
 * after a flush (this function is never call without a flush before). This 
 * allows to the display driver to wait the right moment the graphics buffer
 * becomes ready to be used by the display stack. This synchronization avoids
 * flickering.<br>
 * This function is optional and can do nothing.
 * @see LLDISPLAY_flush
 */
void LLDISPLAY_IMPL_synchronize(void);
