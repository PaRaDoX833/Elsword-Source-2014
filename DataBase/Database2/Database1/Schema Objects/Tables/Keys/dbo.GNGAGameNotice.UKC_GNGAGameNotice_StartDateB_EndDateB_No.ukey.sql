﻿ALTER TABLE [dbo].[GNGAGameNotice] ADD CONSTRAINT [UKC_GNGAGameNotice_StartDateB_EndDateB_No] UNIQUE CLUSTERED  ([StartDateB], [EndDateB], [No]) WITH FILLFACTOR=80 ON [PRIMARY]

